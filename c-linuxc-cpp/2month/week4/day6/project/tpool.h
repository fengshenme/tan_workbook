#ifndef __TPOOL_H
#define __TPOOL_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 20
#define MAX_TASKS 1000

struct tasknode{
	
	void *(*task)(void *);//任意类型转换的函数
	void *arg;//参数
	struct tasknode *next;
};

struct tpool{
	
	pthread_mutex_t m;
	pthread_cond_t v;
	bool shutdown;
	struct tasknode *tasks;
	
	pthread_t *tids;
	
	unsigned int waiting_tasks;
	unsigned int max_threads;
	
	unsigned int active_threads;
	unsigned int max_tasks;	
};

bool init_pool(struct tpool *pool, unsigned int thread_num);
bool add_task(struct tpool *pool, void *(task)(void *), void *arg);
bool destroy_pool(struct tpool *pool);

#endif


