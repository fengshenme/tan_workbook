#include "thread_pool.h"





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

