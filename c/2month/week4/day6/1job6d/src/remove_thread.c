#include "thread_pool.h"




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

