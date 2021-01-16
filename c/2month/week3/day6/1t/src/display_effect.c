#include "../include/head4animation.h"



void a_falling_down_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH])
{

	
	int i;
	for(i=0; i<HEIGHT; i++)
	{
		memcpy(&FB[0][0], &image[HEIGHT-i-1][0],
						WIDTH*4*(i+1));
		usleep(1000);
	}
}

// void a_falling_down_out(int lcd, unsigned long (*image)[WIDTH])
// {

// 	int i;
// 	for(i=0; i<=HEIGHT; i++)
// 	{
// 		memset(&FB[0][0], 0, WIDTH*4*i);
// 		memcpy(&FB[i][0], &image[0][0],
// 					WIDTH*4*(HEIGHT-i));
// 		usleep(1000);
// 	}
// }


// void a_falling_down(int lcd, unsigned long (*image)[WIDTH])
// {
// 	falling_down_in(lcd, image);
// 	falling_down_out(lcd, image);
// }