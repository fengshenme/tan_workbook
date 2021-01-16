#include "thread_pool.h"

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

