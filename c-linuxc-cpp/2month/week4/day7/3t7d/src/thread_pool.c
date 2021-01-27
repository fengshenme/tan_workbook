#include "../include/thread_pool.h"

/**
 * @brief 响应取消请求之后自动处理的例程：释放互斥锁
 * 
 * @param arg 
 */
void handler(void *arg) 
{
	printf("[%u] is ended.\n", (unsigned)pthread_self());

	pthread_mutex_unlock((pthread_mutex_t *)arg);
}

/**
 * @brief 线程例程函数
 * 
 * @param arg 
 * @return void* 
 */
void *routine(void *arg)
{
	thread_pool *pool = (thread_pool *)arg;
	struct task *p;

	while(1)
	{
		// 访问任务队列前加锁，为防止取消后死锁，注册处理例程 handler
		pthread_cleanup_push(handler, (void *)&pool->lock); // 收到取消请求时执行
		
		pthread_mutex_lock(&pool->lock); //上锁


		// 若当前没有任务，且线程池未关闭，则进入条件变量等待队列睡眠
		while(pool->waiting_tasks == 0 && !pool->shutdown)
		{
			pthread_cond_wait(&pool->cond, &pool->lock); //自动解锁
		}
		
		// 若当前没有任务，且线程池关闭标识为真，则立即释放互斥锁并退出
		if(pool->waiting_tasks == 0 && pool->shutdown == true)
		{	
			pthread_mutex_unlock(&pool->lock);	//解锁
			
			pthread_exit(NULL);  //退出线程
		}
		
		// 若当前有任务，则消费任务队列中的任务
		p = pool->task_list->next;
		
		pool->task_list->next = p->next;
		
		pool->waiting_tasks--;  //等待任务数减1

		// 释放互斥锁，并弹栈 handler（但不执行他）
		pthread_mutex_unlock(&pool->lock);
		
		pthread_cleanup_pop(0);
		
		// 执行任务，并且在此期间禁止响应取消请求
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL); 
		
		(p->do_task)(p->arg);
		
		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
		//释放空间
		free(p);
	}

	pthread_exit(NULL); //退出
}


bool init_pool(thread_pool *pool, unsigned int threads_number)
{
	pthread_mutex_init(&pool->lock, NULL); //初始化互斥锁
	
	pthread_cond_init(&pool->cond, NULL); // 初始化条件变量

	pool->shutdown = false; // 线程池关闭标识为假(未关闭)
	
	pool->task_list = malloc(sizeof(struct task));  // 任务队列头节点
	
	pool->tids = malloc(sizeof(pthread_t) * MAX_ACTIVE_THREADS);  // 线程

	if(pool->task_list == NULL || pool->tids == NULL) // 检测内存是否分配错误
	{
		perror("allocate memory error");  // 内存分配失败
		return false; //退出函数
	}

	pool->task_list->next = NULL; // 任务节点指针
	
	pool->max_waiting_tasks = MAX_WAITING_TASKS;  // 设置任务最大等待数

	pool->waiting_tasks = 0;  // 起始等待任务数0
	
	pool->active_threads = threads_number; //初始化活跃线程

	int i;
	for(i=0; i<pool->active_threads; i++) // 创建指定数目线程
	{
		if(pthread_create(&((pool->tids)[i]), NULL,routine, (void *)pool) != 0) //检测线程是否创建成功
		{
			perror("create threads error");  // 线程创建失败
			return false; //退出函数
		}
	}

	return true;  // 初始化成功
}



bool add_task(thread_pool *pool,void *(*do_task)(void *arg), void *arg)
{
	struct task *new_task = malloc(sizeof(struct task)); // 给新任务节点分配内存
	if(new_task == NULL)  // 检测任务内存分配是否成功
	{
		perror("allocate memory error"); //分配内存失败
		return false; // 任务添加失败
	}
	
	new_task->do_task = do_task;  // 赋值例程函数指针
	new_task->arg = arg; // 赋值例程函数的参数指针
	new_task->next = NULL;  // 任务节点指针
	
	pthread_mutex_lock(&pool->lock); // 上锁
	
	if(pool->waiting_tasks >= MAX_WAITING_TASKS) //检测任务数量是否已超过最大数量
	{
		pthread_mutex_unlock(&pool->lock); // 解锁
		
		fprintf(stderr, "too many tasks.\n"); //打印信息,提示任务太多
		
		free(new_task); // 释放内存

		return false; // 任务添加失败退出
	}
	
	struct task *tmp = pool->task_list; // 赋值任务队列头节点指针
	while(tmp->next != NULL) // 遍历到队列尾部
		tmp = tmp->next;
	
	tmp->next = new_task; // 添加到队尾
	
	pool->waiting_tasks++; // 等待任务数加一

	pthread_mutex_unlock(&pool->lock); // 释放互斥锁

	pthread_cond_signal(&pool->cond); // 唤醒其中一个阻塞在条件变量上的线程
	
	return true;  //添加成功
}


int add_thread(thread_pool *pool, unsigned additional_threads)
{
	if(additional_threads == 0) // 新增线程个数为0 则返回0
		return 0; 

	unsigned total_threads = pool->active_threads + additional_threads; // 求得预增加后的总线程数
						
	int i, actual_increment = 0; // 定义的变量
	
	for(i = pool->active_threads;  
	    i < total_threads && i < MAX_ACTIVE_THREADS;  
	    i++)  // 遍历创建线程
	   {
		if(pthread_create(&((pool->tids)[i]),NULL, routine, (void *)pool) != 0)
		{
			perror("add threads error"); //线程添加失败
			if(actual_increment == 0)  // 如果所有线程添加都失败就直接退出
				return -1;

			break;
		}
		actual_increment++;  // 添加成功线程数
	}

	pool->active_threads += actual_increment;   //新的线程总数
	return actual_increment;  // 实际增加线程数
}

     
int remove_thread(thread_pool *pool, unsigned int removing_threads)
{
	if(removing_threads == 0)  // 如果需删除线程个数为0 则返回目前活动线程数
		return pool->active_threads; 
	// 预减少线程后的可能活跃线程数
	int remaining_threads = pool->active_threads - removing_threads;
	// 如果预减少线程后总线程数小于0,则减少到剩一个
	remaining_threads = remaining_threads > 0 ? remaining_threads : 1;

	int i;  
	for(i=pool->active_threads-1; i>remaining_threads-1; i--) //遍历到减少到目标数量值
	{	
		errno = pthread_cancel(pool->tids[i]); //取消线程数
		if(errno != 0)		// 如果线程取消失败退出循环
			break;
	}

	if(i == pool->active_threads-1) // 如果没有取消成功一个线程直接返回失败-1
		return -1;
	else
	{
		pool->active_threads = i+1;  // 剩余活跃线程数
		return i+1; 
	}
}


bool destroy_pool(thread_pool *pool)
{
	
	pool->shutdown = true;  //线程池关闭标识为真(变为关闭状态)
	
	pthread_cond_broadcast(&pool->cond);  // 通知条件变量中线程
	
	
	int i;
	for(i=0; i<pool->active_threads; i++)  // 接合还存在的线程
	{
		errno = pthread_join(pool->tids[i], NULL);

		if(errno != 0)
		{
			printf("join tids[%d] error: %s\n",
					i, strerror(errno));
		}
	
		else
			printf("[%u] is joined\n", (unsigned)pool->tids[i]);
		
	}

	
	free(pool->task_list); // 释放内存
	free(pool->tids);
	free(pool);

	return true;
}

