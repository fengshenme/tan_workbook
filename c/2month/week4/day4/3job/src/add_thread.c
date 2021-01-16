#include "thread_pool.h"



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
