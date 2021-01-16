#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include <errno.h>
#include <pthread.h>

#define MAX_WAITING_TASKS 10000
#define MAX_ACTIVE_THREADS 50

// 通过链表连成一个任务队列
struct task // 任务节点 含需要执行的函数及其参数
{
	void *(*do_task)(void *arg); // 例程函数
	void *arg;					 // 例程函数的参数

	struct task *next; // 任务节点指针
};

typedef struct thread_pool //线程池结构体
{
	pthread_mutex_t lock;		// 互斥锁
	pthread_cond_t cond;		//条件变量
	bool shutdown;				//线程池销毁标记
	struct task *task_list;		// 任务链队列指针
	pthread_t *tids;			// 线程id存放地址
	unsigned max_waiting_tasks; // 任务链队列中能等待的任务个数上限
	unsigned waiting_tasks;		// 任务链队列中等待的任务个数
	unsigned active_threads;	// 当前活跃线程个数
} thread_pool;					// 活跃线程个数可修改，但至少有 1 条活跃线程

/**
 * @brief 创建一个新的线程池，包含 threads_number 个活跃线程
 * 线程池最少线程个数为 1
 * 
 * @param pool 线程池指针 
 * @param threads_number 初始活跃线程个数（大于等于 1）
 * @return 成功返回 true 
 * @return 失败返回 false 
 */
bool init_pool(thread_pool *pool, unsigned int threads_number);

/**
 * @brief 往线程池投送任务
 * 任务队列中最大任务个数为 MAX_WAITING_TASKS
 * @param pool 线程池指针
 * @param do_task 投送至线程池的执行例程
 * @param task 执行例程 do_task 的参数，若该执行例程不需要参数可设置为 NULL
 * @return 成功返回 true 
 * @return 失败返回 false
 */
bool add_task(thread_pool *pool, void *(*do_task)(void *arg), void *task);

/**
 * @brief 增加线程池中活跃线程的个数
 * 
 * @param pool 需要增加线程的线程池指针
 * @param additional_threads_number 新增线程个数
 * @return int >0 : 实际新增线程个数
 * @return int -1 : 失败
 */
int add_thread(thread_pool *pool, unsigned int additional_threads_number);

/**
 * @brief 删除线程池中活跃线程的个数
 * 1，线程池至少会存在 1 条活跃线程 
 * 2，如果被删除的线程正在执行任务，则将等待其完成任务之后删除
 * 
 * @param pool 需要删除线程的线程池指针
 * @param removing_threads_number 要删除的线程个数。该参数设置为 0 时直接返回当前 线程池线程总数，对线程池不造成任何其它影响
 * @return int >0: 当前线程池剩余线程个数
 * @return int -1: 失败
 */
int remove_thread(thread_pool *pool, unsigned int removing_threads_number);

/**
 * @brief 阻塞等待所有任务完成，然后立即销毁整个线程池，释放所有资源和内存
 * 
 * @param pool 将要销毁的线程池
 * @return 成功返回 true 
 * @return 失败返回 false 
 */
bool destroy_pool(thread_pool *pool);

/**
 * @brief // 线程例程
 * 
 * @param arg 
 * @return void* 
 */
void *routine(void *arg);

#endif
