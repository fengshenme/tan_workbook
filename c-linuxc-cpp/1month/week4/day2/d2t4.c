////////////////////////////////////////////////////////////////////
//
//  Copyright(C), 2013-2016, GEC Tech. Co., Ltd.
//
//  File name: GPLE/ch06/6.3/get_screeninfo.c  
//
//  Author: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  Date: 2016-3
//  
//  Description: 获取LCD设备硬件参数
//
//  GitHub: github.com/vincent040   Bug Report: 2437231462@qq.com
//
////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <linux/fb.h>

#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

void show_fix_screeninfo(struct fb_fix_screeninfo *p) //固定属性
{
	printf("=== FIX SCREEN INFO === \n");

	printf("\tid: %s\n", p->id);
	printf("\tsmem_start: %#x\n", p->smem_start);
	printf("\tsmem_len: %u bytes\n", p->smem_len);  // 硬件显存大小（字节）

	printf("\ttype:");
	switch(p->type)
	{
	case FB_TYPE_PACKED_PIXELS:
		printf("PACKED_PIXELS\n");break;
	case FB_TYPE_PLANES:
		printf("PLANES\n");break;
	case FB_TYPE_INTERLEAVED_PLANES:
		printf("INTERLEAVED_PLANES\n");break;
	case FB_TYPE_TEXT:
		printf("TEXT\n");break;
	case FB_TYPE_VGA_PLANES:
		printf("VGA_PLANES\n");break;
	}

	printf("\tvisual:");
	switch(p->visual)
	{
	case FB_VISUAL_MONO01:
		printf("MONO01\n");break;
	case FB_VISUAL_MONO10:
		printf("MONO10\n");break;
	case FB_VISUAL_TRUECOLOR:
		printf("TRUECOLOR\n");break;
	case FB_VISUAL_PSEUDOCOLOR:
		printf("PSEUDOCOLOR\n");break;
	case FB_VISUAL_DIRECTCOLOR:
		printf("DIRECTCOLOR\n");break;
	case FB_VISUAL_STATIC_PSEUDOCOLOR:
		printf("STATIC_PSEUDOCOLOR\n");break;
	}

	printf("\txpanstep: %u\n", p->xpanstep);
	printf("\typanstep: %u\n", p->ypanstep);
	printf("\tywrapstep: %u\n", p->ywrapstep);
	printf("\tline_len: %u bytes\n", p->line_length); // 一行扫描线大小（字节)

	printf("\tmmio_start: %#x\n", p->mmio_start);
	printf("\tmmio_len: %u bytes\n", p->mmio_len);

	printf("\taccel: ");
	switch(p->accel)
	{
	case FB_ACCEL_NONE: printf("none\n"); break;
	default: printf("unkown\n");
	}

	printf("\n");
}

void show_var_screeninfo(struct fb_var_screeninfo *p) // 可变属性
{
	printf("=== VAR SCREEN INFO === \n");

	printf("\thsync_len: %u\n", p->hsync_len);
	printf("\tvsync_len: %u\n", p->vsync_len);
	printf("\tvmode: %u\n", p->vmode);

	printf("\tvisible screen size: %ux%u\n",
				p->xres, p->yres); // 可见区尺寸
	printf("\tvirtual screen size: %ux%u\n\n",
				p->xres_virtual,
				p->yres_virtual); // 虚拟区尺寸

	printf("\tbits per pixel: %u\n", p->bits_per_pixel);
	printf("\tactivate: %u\n\n", p->activate);

	printf("\txoffset: %d\n", p->xoffset); // 当前 X 轴偏移量
	printf("\tyoffset: %d\n", p->yoffset); // 当前 Y 轴偏移量

	printf("\tcolor bit-fields:\n"); // 色彩构成
	printf("\tR: [%u:%u]\n", p->red.offset,
			       p->red.offset+p->red.length-1); // 一个 pisel 中的第 16 位到第 23 位表示红色的色彩数值
	printf("\tG: [%u:%u]\n", p->green.offset,
			       p->green.offset+p->green.length-1); // 一个 pisel 中的第 8 位到第 15 位表示绿色的色彩数值
	printf("\tB: [%u:%u]\n\n", p->blue.offset,
			       p->blue.offset+p->blue.length-1); // 一个 pisel 中的第 0 位到第 7 位表示蓝色的色彩数值

	printf("\n");
}

int main(void)
{
	int lcd = open("/dev/fb0", O_RDWR|O_EXCL);
	if(lcd == -1)
	{
		perror("open()");
		exit(1);
	}

	struct fb_fix_screeninfo finfo; // 显卡设备的固定属性结构体
	struct fb_var_screeninfo vinfo;	// 显卡设备的可变属性结构体

	ioctl(lcd, FBIOGET_FSCREENINFO, &finfo); // 获取固定属性
	ioctl(lcd, FBIOGET_VSCREENINFO, &vinfo); // 获取可变属性

	show_fix_screeninfo(&finfo); // 打印相应的属性
	show_var_screeninfo(&vinfo);
	// 将显示设备的具体信息保存起来，方便使用
	unsigned long WIDTH  = vinfo.xres;
	unsigned long HEIGHT = vinfo.yres;
	unsigned long VWIDTH  = vinfo.xres_virtual;
	unsigned long VHEIGHT = vinfo.yres_virtual;
	unsigned long BPP = vinfo.bits_per_pixel;

	char *p = mmap(NULL, VWIDTH * VHEIGHT * BPP/8,
			PROT_READ|PROT_WRITE,
			MAP_SHARED, lcd, 0);  // 申请一块虚拟区映射内存

	int image = open("images/girl.bin", O_RDWR);
	int image_size = lseek(image, 0L, SEEK_END);
	lseek(image, 0L, SEEK_SET);
	read(image, p, image_size); // 获取图片数据并将之刷到映射内存


	vinfo.xoffset = 0;
	vinfo.yoffset = 0;
	if(ioctl(lcd, FB_ACTIVATE_NOW, &vinfo)) // 偏移量均置位为 0
	{
		perror("ioctl()");
	}
	ioctl(lcd, FBIOPAN_DISPLAY, &vinfo); // 配置属性并扫描显示

	sleep(1);

	vinfo.xoffset = 0;
	vinfo.yoffset = 100;
	if(ioctl(lcd, FB_ACTIVATE_NOW, &vinfo)) // 1 秒钟之后将 Y 轴偏移量调整为 100 像素
	{
		perror("ioctl()");
	}
	show_var_screeninfo(&vinfo);
	ioctl(lcd, FBIOPAN_DISPLAY, &vinfo); // 重新配置属性并扫描显示

	return 0;
}
