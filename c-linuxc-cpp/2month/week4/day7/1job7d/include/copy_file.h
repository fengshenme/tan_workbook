#ifndef _COPY_FILE_H_
#define _COPY_FILE_H_

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>

#include "thread_pool.h"

typedef struct fd_path
{
    
    char c_path[256]; // 避免乱码
    char s_path[256];
    char d_path[256];
    thread_pool *pool;
    unsigned int perm;

    
} plural_path;

typedef struct f_path
{
    
    char * c_path; // 避免乱码
    char * s_path;
    char * d_path;
    thread_pool *pool;
    unsigned int perm;

    
} plur_path;

void *pfiletofile(void * arg);

int copy2(char *src_path, char *des_path, thread_pool *pool);


/**
 * @brief 文件复制
 * 
 * @param src_path 源文件绝对路径
 * @param des_path 目标文件绝对路径
 * @param perm 文件权限 8进制
 * @return int 
 */
int filetofile(char *src_path, char *des_path, unsigned int perm);

/**
 * @brief 文件复制到目录下
 * 
 * @param src_path 
 * @param des_path 
 * @param perm 文件权限 8进制
 * @return int 
 */
int filetodir(char *src_path, char *des_path, unsigned int perm);


/**
 * @brief 目录复制到目录下
 * 
 * @param src_path 
 * @param des_path 
 * @param perm 
 * @return int 
 */
int dirtodir(char *src_path, char *des_path, unsigned int perm);

/**
 * @brief 复制 
 * 
 * @param src_path 
 * @param des_path 
 * @return int 
 */
int copy(char *src_path, char *des_path);

void * p_copy_file(void * arg);

/**
 * @brief 将输入路径转换为绝对路径
 * 
 * @param src_path 
 * @return int 
 */
int trans_dir(char *src_path);

#endif