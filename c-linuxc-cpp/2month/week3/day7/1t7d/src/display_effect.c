/**
 * @file display_effect.c
 * @author 
 * @brief 各种图像显示效果
 * @version 0.1
 * @date 2020-11-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../include/head4animation.h"


/**
 * @brief  从上而下显示图片
 * 
 */
void falling_down_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	
	int i;
	for(i=0; i<HEIGHT; i++)
	{
		memcpy(&FB[0][0], &image[HEIGHT-i-1][0],
						WIDTH*4*(i+1));
		usleep(1000);
	}
}

/**
 * @brief 从上而下消除图片
 * 
 */
void falling_down_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	int i;
	for(i=0; i<=HEIGHT; i++)
	{
		memset(&FB[0][0], 0, WIDTH*4*i);
		memcpy(&FB[i][0], &image[0][0],
					WIDTH*4*(HEIGHT-i));
		usleep(1000);
	}
}

/**
 * @brief 图片从上而下掉落，穿过显示屏。
 * 
 */
void falling_down(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	falling_down_in(FB, image);
	falling_down_out(FB, image);
}

/**
 * @brief 从上而下显示图片
 * 
 */
void floating_up_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	int i = 0;
	
	while(1)
	{
		memcpy(&FB[HEIGHT-i-1][0], &image[0][0],
						WIDTH*4*(i+1));
		if(i >= HEIGHT-1)
			break;

		usleep(1000);
		i++;
	}
}

/**
 * @brief  从下而上消除图片
 * 
 * @param lcd 
 */
void floating_up_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	int i;
	for(i=0; i<=HEIGHT; i++)
	{
		memset(&FB[HEIGHT-i][0], 0, WIDTH*4*i);
		memcpy(&FB[0][0], &image[i][0],
					WIDTH*4*(HEIGHT-i));
		usleep(1000);
	}
}

/**
 * @brief 图片上浮穿过显示屏
 * 
 */
void floating_up(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	floating_up_in(FB, image);
	floating_up_out(FB, image);
}

/**
 * @brief 图片从左往右入
 * 
 */
void left2right_in(unsigned long (*FB)[WIDTH] , unsigned long (*image)[WIDTH])
{

	int i, j;
	for(i=0; i<WIDTH; i++)
	{
		for(j=0; j<HEIGHT; j++)
		{
			memcpy(&FB[j][0],
				&image[j][WIDTH-1-i], 4*(i+1));
		}
	}
}

/**
 * @brief 图片从左往右出
 * 
 */
void left2right_out(unsigned long (*FB)[WIDTH] , unsigned long (*image)[WIDTH])
{
	int i, j;
	for(i=0; i<WIDTH; i++)
	{
		for(j=0; j<HEIGHT; j++)
		{
			memset(&FB[j][0], 0, 4*(i+1));
			memcpy(&FB[j][i+1],
				&image[j][0], (WIDTH-1-i)*4);
		}
	}
}

/**
 * @brief 图片从左到右移动
 * 
 */
void left_2_right(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	left2right_in(FB, image);
	left2right_out(FB, image);
}

/**
 * @brief 图片从右往左入
 * 
 */
void right2left_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	int i, j;
	for(i=0; i<WIDTH; i++)
	{
		for(j=0; j<HEIGHT; j++)
		{
			memcpy(&FB[j][WIDTH-i-1], &image[j][0],
							4*(i+1));
		}
		usleep(100);
	}
}

/**
 * @brief 图片从右往左出
 * 
 */
void right2left_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	int i, j;
	for(i=0; i<WIDTH; i++)
	{
		for(j=0; j<HEIGHT; j++)
		{
			memcpy(&FB[j][0], &image[j][i+1],
						(WIDTH-1-i)*4);
			memset(&FB[j][WIDTH-1-i], 0, (1)*4);
		}
		usleep(100);
	}
}

/**
 * @brief 图片从右向左移动
 * 
 */
void right_2_left(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	right2left_in(FB, image);
	right2left_out(FB, image);
}


#define IN  1
#define OUT 0

/**
 * @brief 百叶窗一个叶片显示
 * 
 * @param p 
 * @return void* 
 */
void *routine(void *p)
{
	struct argument *arg = (struct argument *)p;

	int i;

	if(arg->flag == IN)
	{
		for(i=HEIGHT/BLIND-1; i>=0; i--)
		{
			memcpy(&(arg->FB)[arg->offset+i][0],
		 	       &(arg->image)[arg->offset+i][0],
			       WIDTH*4);

			usleep(10000);
		}
	}

	if(arg->flag == OUT)
	{
		for(i=0; i<HEIGHT/BLIND; i++)
		{
			memset(&(arg->FB)[arg->offset+i][0], 0, WIDTH*4);

			usleep(10000);
		}
	}

	pthread_exit(NULL);
}

void __write_lcd(unsigned long (*p)[WIDTH], unsigned long (*image)[WIDTH], int flag)
{
	int i;
	pthread_t tid[BLIND];
	for(i=0; i<BLIND; i++)
	{
		struct argument *arg =
				malloc(sizeof(struct argument));
		arg->FB = p;
		arg->image = image;
		arg->offset = i*(HEIGHT/BLIND);
		arg->flag = flag;

		pthread_create(&tid[i], NULL, routine, (void *)arg);
	}

	for(i=0; i<BLIND; i++)
	{
		pthread_join(tid[i], NULL);
	}
}

/**
 * @brief 图片入
 * 
 */
void blind_window_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	__write_lcd(FB, image, IN); 
}

/**
 * @brief 图片出
 * 
 */
void blind_window_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	__write_lcd(FB, image, OUT); 
}

/**
 * @brief 百叶窗效果
 * 
 */
void blind_window(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{
	blind_window_in(FB, image);
	blind_window_out(FB, image);
}
