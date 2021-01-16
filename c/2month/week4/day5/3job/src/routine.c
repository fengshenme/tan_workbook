#include "thread_pool.h"

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
