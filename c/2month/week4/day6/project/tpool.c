#include "tpool.h"

void handler_lock(void *arg)
{
	pthread_mutex_unlock((pthread_mutex_t *)arg);
}

void *routine(void *arg)
{
	struct tpool *pool = (struct tpool *)arg;
	
	while(1)
	{
		//存放取出的任务节点的临时变量
		struct tasknode *tmp;
		
		//访问任务队列，加锁
		//当加锁时被取消，就会执行该函数，帮你解锁
		pthread_cleanup_push(handler_lock,(void *)&pool->m);
		pthread_mutex_lock(&pool->m);
		
		//1.没有任务，并且线程池正常，则自动解锁进入条件变量等待任务的到来
		while(pool->waiting_tasks == 0 && pool->shutdown != true)
		{
			//醒后自动加锁，访问任务队列中的数目waitint_tasks
			//如果在此函数睡眠时受到取消请求，那么以下的函数在返回前会响应该请求
			//因为这个函数是取消点，就是有可能带着一把锁死掉
			pthread_cond_wait(&pool->v,&pool->m);
		}
		
		//2.没有任务，线程池被关闭，直接解锁走人
		if(pool->waiting_tasks == 0 && pool->shutdown == true)
		{
			pthread_mutex_unlock(&pool->m);
			pthread_exit(NULL);
		}
		
		//3.有任务，则消费队列中的任务
		//获取第一个任务节点
		tmp = pool->tasks->next;
		pool->tasks->next = tmp->next;
		tmp->next = NULL;
		
		//消费等待任务的数量
		pool->waiting_tasks--;
		
		//做完任务，正常退出
		pthread_mutex_unlock(&pool->m);
		pthread_cleanup_pop(0);
		
		//在执行任务期间，不响应取消请求
		pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,NULL);
		
		//执行队列中的函数
		(tmp->task)(tmp->arg);
		
		//执行完可以取消
		pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
		
		//释放临时变量内存
		free(tmp);
	}
	
	pthread_exit(NULL);
}

bool init_pool(struct tpool *pool, unsigned int thread_num)
{
	if(pool == NULL)
		return false;
	
	pthread_mutex_init(&pool->m,NULL);
	pthread_cond_init(&pool->v,NULL);

	pool->tasks = malloc(sizeof(struct tasknode));
	if(pool->tasks == NULL)
	{
		printf("pool->task malloc error!\n");
		return false;
	}
	
	pool->tasks->next = NULL;
	
	pool->shutdown = false;
	
	pool->tids = calloc(thread_num,sizeof(pthread_t));
	
	int i;
	for(i=0;i<thread_num;i++)
	{
		if((errno=pthread_create(&pool->tids[i],NULL,routine,(void *)pool))!=0)
		{
			printf("pthread_create!\n");
			return false;
		}	
	}
	
	pool->waiting_tasks = 0;
	pool->max_tasks = MAX_TASKS;
	
	pool->max_threads = MAX_THREADS;
	pool->active_threads = thread_num;
	
	return true;	
}

bool add_task(struct tpool *pool, void *(task)(void *), void *arg)
{
	//新建任务节点
	struct tasknode *new = (struct tasknode *)malloc(sizeof(struct tasknode));
	if(new != NULL)
	{
		new->task = task;
		new->arg = arg;
		new->next = NULL;
	}
	
	//访问任务队列，加锁
	pthread_mutex_lock(&pool->m);
	
	//如果任务达到最大值，解锁返回添加任务失败
	if(pool->waiting_tasks>=MAX_TASKS)
	{
		pthread_mutex_unlock(&pool->m);		
		free(new);
		return false;
	}
	
	//把节点放到链表尾部
	//p指向链表头
	struct tasknode *p = pool->tasks;
	while(p->next != NULL)
	{
		p = p->next;
	}
	
	p->next = new;
	
	pool->waiting_tasks++;
	
	//添加完，解锁
	pthread_mutex_unlock(&pool->m);
	
	//发出唤醒，让睡眠的某条线程处理这个任务
	pthread_cond_signal(&pool->v);
	
	return true;
}

//把全部睡眠的线程全部叫醒，让他们全部走人
bool destroy_pool(struct tpool *pool)
{	
	pool->shutdown = true;
	
	//发出通知，叫醒全部睡眠的线程
	pthread_cond_broadcast(&pool->v);
	
	int i;
	for(i=0;i<pool->active_threads;i++)
	{
		errno = pthread_join(pool->tids[i],NULL);
		if(errno != 0)
		{
			printf("pthread_join error!\n");
			return false;
		}
		else
		{
			printf("[%d] is join!\n",(int)pool->tids[i]);
		}
	}
	
	//释放所有的堆内存空间
	free(pool->tasks);
	free(pool->tids);
	free(pool);
	
	return true;
	
}

