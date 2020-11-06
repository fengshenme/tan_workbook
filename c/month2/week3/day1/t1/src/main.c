////////////////////////////////////////////////////////////////////
//
//  Copyright(C), 2013-2016, GEC Tech. Co., Ltd.
//
//  File name: GPLE/ch06/6.3/jpeg_show.c
//
//  Author: Vincent Lin (林世霖)  微信公众号：秘籍酷
//
//  Date: 2016-3
//
//  Description: 使用jpeg库对jpeg图片解码，然后写入显存中
//
//  GitHub: github.com/vincent040   Bug Report: 2437231462@qq.com
//
////////////////////////////////////////////////////////////////////

#include "../include/head4animation.h"

struct image_info
{
	int width;
	int height;
	int pixel_size;
};

void write_lcd_t(unsigned long(*image)[WIDTH], unsigned char *bmp_buffer, struct image_info *imageinfo,
				 unsigned char *FB, struct fb_var_screeninfo *vinfo);

// 将bmp_buffer中的24bits的RGB数据，写入LCD的32bits的显存中
void write_lcd(unsigned char *bmp_buffer, struct image_info *imageinfo,
			   unsigned char *FB, struct fb_var_screeninfo *vinfo);

// 将jpeg文件的压缩图像数据读出，放到jpg_buffer中去等待解压
unsigned long read_image_from_file(int fd,
								   unsigned char *jpg_buffer,
								   unsigned long jpg_size);

int Stat(const char *filename, struct stat *file_info);

int Open(const char *filename, int mode);

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <jpeg image>\n", argv[0]);
		exit(1);
	}

	// 读取图片文件属性信息
	// 并根据其大小分配内存缓冲区jpg_buffer
	struct stat file_info;
	Stat(argv[1], &file_info);
	int fd = Open(argv[1], O_RDONLY);

	unsigned char *jpg_buffer;
	jpg_buffer = (unsigned char *)calloc(1, file_info.st_size);
	read_image_from_file(fd, jpg_buffer, file_info.st_size);

	// 声明解压缩结构体，以及错误管理结构体
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;

	// 使用缺省的出错处理来初始化解压缩结构体
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);

	// 配置该cinfo，使其从jpg_buffer中读取jpg_size个字节
	// 这些数据必须是完整的JPEG数据
	jpeg_mem_src(&cinfo, jpg_buffer, file_info.st_size);

	// 读取JPEG文件的头，并判断其格式是否合法
	int ret = jpeg_read_header(&cinfo, true);
	if (ret != 1)
	{
		fprintf(stderr, "[%d]: jpeg_read_header failed: "
						"%s\n",
				__LINE__, strerror(errno));
		exit(1);
	}

	// 开始解压
	jpeg_start_decompress(&cinfo);

	struct image_info imageinfo;
	imageinfo.width = cinfo.output_width;
	imageinfo.height = cinfo.output_height;
	imageinfo.pixel_size = cinfo.output_components;

	int row_stride = imageinfo.width * imageinfo.pixel_size;

	// 根据图片的尺寸大小，分配一块相应的内存bmp_buffer
	// 用来存放从jpg_buffer解压出来的图像数据
	unsigned long bmp_size;
	unsigned char *bmp_buffer;
	bmp_size = imageinfo.width * imageinfo.height * imageinfo.pixel_size;
	bmp_buffer = (unsigned char *)calloc(1, bmp_size);

	// 循环地将图片的每一行读出并解压到bmp_buffer中  // unsigned long (*image)[WIDTH]
	// int line = 0;
	while (cinfo.output_scanline < cinfo.output_height)
	{
		unsigned char *buffer_array[1];
		buffer_array[0] = bmp_buffer + (cinfo.output_scanline) * row_stride;
		jpeg_read_scanlines(&cinfo, buffer_array, 1);
		// jpeg_read_raw_data(&cinfo,buffer_array,1);
	}

	// 解压完了，将jpeg相关的资源释放掉
	jpeg_finish_decompress(&cinfo);
	jpeg_destroy_decompress(&cinfo);
	free(jpg_buffer);

	// 准备LCD屏幕
	int lcd = Open("/dev/fb0", O_RDWR | O_EXCL);

	// 获取LCD设备的当前参数
	struct fb_var_screeninfo vinfo;
	ioctl(lcd, FBIOGET_VSCREENINFO, &vinfo);

	// 根据当前LCD设备参数申请适当大小的FRAMEBUFFR
	unsigned char *FB;
	unsigned long bpp = vinfo.bits_per_pixel;
	FB = mmap(NULL, vinfo.xres * vinfo.yres * bpp / 8,
			  PROT_READ | PROT_WRITE, MAP_SHARED, lcd, 0);

	// 将bmp_buffer中的RGB图像数据，写入LCD的FRAMEBUFFER中
	// write_lcd(bmp_buffer, &imageinfo, FB, &vinfo);

	// unsigned long *image = calloc(SCREEN_SIZE, 4);
	unsigned long(*image)[WIDTH] = calloc(SCREEN_SIZE, 4);
	unsigned long(*FB1)[WIDTH] = mmap(NULL, WIDTH * HEIGHT * 4,
									  PROT_READ | PROT_WRITE,
									  MAP_SHARED, lcd, 0);

	write_lcd_t(image, bmp_buffer, &imageinfo, FB, &vinfo);

	
	printf("%lx \n", *image[200] );


	munmap(FB, SCREEN_SIZE);  //解除映射

	a_falling_down_in(FB1, image);


	free(image);
	munmap(FB1, SCREEN_SIZE); //解除映射
	close(lcd);
	close(fd);

	return 0;
}

// 将bmp_buffer中的24bits的RGB数据，写入LCD的32bits的显存中
void write_lcd_t(unsigned long(*image)[WIDTH], unsigned char *bmp_buffer, struct image_info *imageinfo,
				 unsigned char *FB, struct fb_var_screeninfo *vinfo)
{
	bzero(FB, vinfo->xres * vinfo->yres * 4);

	int x, y, i = 0;
	for (x = 0; x < vinfo->yres && x < imageinfo->height; x++)
	{
		for (y = 0; y < vinfo->xres && y < imageinfo->width; y++)
		{
			unsigned long lcd_offset = (vinfo->xres * x + y) * 4;
			unsigned long bmp_offset = (imageinfo->width * x + y) *
									   imageinfo->pixel_size;

			// image
			memcpy(FB + lcd_offset + vinfo->red.offset / 8, bmp_buffer + bmp_offset + 0, 1);
			memcpy(FB + lcd_offset + vinfo->green.offset / 8, bmp_buffer + bmp_offset + 1, 1);
			memcpy(FB + lcd_offset + vinfo->blue.offset / 8, bmp_buffer + bmp_offset + 2, 1);

			unsigned char tmpc[4];

			tmpc[0] = 0x00;
			tmpc[1] = *(bmp_buffer + bmp_offset + 0);
			tmpc[2] = *(bmp_buffer + bmp_offset + 1);
			tmpc[3] = *(bmp_buffer + bmp_offset + 2);
			
			image[x][y] = (tmpc[0] << 24 | tmpc[1] << 16 | tmpc[2] << 8 | tmpc[3] << 0);
			i++;	
		}
	}
}

// 将bmp_buffer中的24bits的RGB数据，写入LCD的32bits的显存中
void write_lcd(unsigned char *bmp_buffer, struct image_info *imageinfo,
			   unsigned char *FB, struct fb_var_screeninfo *vinfo)
{
	bzero(FB, vinfo->xres * vinfo->yres * 4);

	int x, y;
	for (x = 0; x < vinfo->yres && x < imageinfo->height; x++)
	{
		for (y = 0; y < vinfo->xres && y < imageinfo->width; y++)
		{
			unsigned long lcd_offset = (vinfo->xres * x + y) * 4;
			unsigned long bmp_offset = (imageinfo->width * x + y) *
									   imageinfo->pixel_size;

			memcpy(FB + lcd_offset + vinfo->red.offset / 8,
				   bmp_buffer + bmp_offset + 0, 1);
			memcpy(FB + lcd_offset + vinfo->green.offset / 8,
				   bmp_buffer + bmp_offset + 1, 1);
			memcpy(FB + lcd_offset + vinfo->blue.offset / 8,
				   bmp_buffer + bmp_offset + 2, 1);
		}
	}
}

// 将jpeg文件的压缩图像数据读出，放到jpg_buffer中去等待解压
unsigned long read_image_from_file(int fd,
								   unsigned char *jpg_buffer,
								   unsigned long jpg_size)
{
	unsigned long nread = 0;
	unsigned long total = 0;

	while (jpg_size > 0)
	{
		nread = read(fd, jpg_buffer, jpg_size);

		jpg_size -= nread;
		jpg_buffer += nread;
		total += nread;
	}
	close(fd);

	return total;
}

int Stat(const char *filename, struct stat *file_info)
{
	int ret = stat(filename, file_info);

	if (ret == -1)
	{
		fprintf(stderr, "[%d]: stat failed: "
						"%s\n",
				__LINE__, strerror(errno));
		exit(1);
	}

	return ret;
}

int Open(const char *filename, int mode)
{
	int fd = open(filename, mode);
	if (fd == -1)
	{
		fprintf(stderr, "[%d]: open failed: "
						"%s\n",
				__LINE__, strerror(errno));
		exit(1);
	}

	return fd;
}
