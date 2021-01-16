#ifndef __HEAD_H
#define __HEAD_H

#include "tpool.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

bool copydir(struct tpool *pool,char *src,char *dst,struct stat *info);
void copyfile(int src, int dst);
void *mytask(void *arg);

#endif