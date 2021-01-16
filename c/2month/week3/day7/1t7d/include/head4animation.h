//////////////////////////////////////////////////////////////////
//
//  Copyright(C), 2013-2016, GEC Tech. Co., Ltd.
//
//  File name: GPLE/ch04/4.4/animation/head4animation.h
//
//  Author: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  Date: 2016-3
//  
//  Description: 图像显示算法头文件
//
//  GitHub: github.com/vincent040   Bug Report: 2437231462@qq.com
//
//////////////////////////////////////////////////////////////////

#ifndef _HEAD4ANIMATION_H_
#define _HEAD4ANIMATION_H_

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <pthread.h>

#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#include <syslog.h>
#include <linux/input.h>
#include <linux/fb.h>

#include "../include/jpeglib.h"

#define SCREEN_SIZE 800*480
#define WIDTH  800
#define HEIGHT 480
#define BLIND  5

struct argument
{
	unsigned long (*FB)[WIDTH];
	unsigned long (*image)[WIDTH];
	int offset;
	int flag;
};

void falling_down_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);
void falling_down_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);
void falling_down(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

void floating_up_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);
void floating_up_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);
void floating_up(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

void left2right_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);
void left2right_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);
void left_2_right(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

void right2left_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);
void right2left_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);
void right2left(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

void blind_window_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);
void blind_window_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);
void blind_window(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

void *routine(void *p);

#endif
