/**
 * @file view_pro.c
 * @author tan wei feng (1015956962@163.com)
 * @brief 视图层相关
 * @version 0.1
 * @date 2020-10-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include "../include/main.h"


int f_tmp = 0; // 重新加载函数的状态码


/**
 * @brief 视图模块初始化
 * 
 * @param pic_list 存储文件绝对路径的数组
 * @param pic_size 目录下扫描出的文件总数
 * @return int  0: 成功 
 * @return int  1: 失败
 */
int view_init(char (*pic_list)[256], int pic_size)
{

    // 1.打开触摸屏文件
    int ts_fd = open_file("/dev/input/event0"); // 触摸屏设备文件描述符
    int lcd_fd = open_file("/dev/fb0");         //lcd设备文件描述符

                 // 映射显存
    // 2.映射显存/dev/input/event0
    unsigned int *fb_l = mem_map(lcd_fd);
    // 初始化字体库
    Init_Font((unsigned long *)fb_l);
    // 3.图片点击切换
    // image_transform(ts_fd, pic_list, pic_size);
    while(1)
    {
        // 3.图片滑动切换
        image_sliding_transform(ts_fd, pic_list, pic_size);
        f_tmp = 0;
    }

    munmap(fb_l, 800 * 480 * 4); //解除映射
    // 4.关闭触摸屏文件显示文件
    close(lcd_fd);
    close(ts_fd);

    return 0;
}

/**
 * 判断是否为目录
 * @param pathname 目录名
 * @return bool 
 * */
bool isdir(const char *pathname)
{
    struct stat file_info;
    int status = stat(pathname, &file_info);
    if (status == 0)
    {
        if (S_ISDIR(file_info.st_mode))
            return true;
    }
    return false;
}

//选择排序方式
void select_sort(int x_tmp, int y_tmp, char (*pic_list)[256])
{

    int x_start = 10, y_start = 10;
    int fs = 32; //字体大小 宽32

    // 清空区域
    // Clean_Area(10, 10, 32*5 , 32, 0xFFFFFF);

    char *str = malloc(200);
    char *tmp = malloc(200);
    // 32*6 32*4 32*5 32*6  fs = 32
    strcpy(tmp, "选择排序方式: 文件名 文件大小 文件创建时间");
    utf8ToGb2312(str, sizeof(200), tmp, strlen(tmp));

    if (y_tmp < fs + y_start)
    {
        int flag = -1;
        if (x_tmp >= fs * 6 + x_start && x_tmp < fs * 6 + fs * 4 + x_start)
        {
            printf("select file name \n");
            flag = 1;
            Clean_Area(fs * 6 + x_start, y_start, fs * 4, fs, 0x00F2F2F2);
        }
        else if (x_tmp >= fs * 6 + fs * 4 + x_start && x_tmp < fs * 6 + fs * 4 + fs * 5 + x_start)
        {
            printf("select file size sort\n");
            flag = 2;
            Clean_Area(fs * 6 + fs * 4 + x_start, y_start, fs * 5, fs, 0x00C8EFD4);
        }
        else if (x_tmp >= fs * 6 + fs * 4 + fs * 5 + x_start && x_tmp < fs * 6 + fs * 4 + fs * 5 + fs * 6 + x_start)
        {
            printf("select file create date\n");
            flag = 0;
            Clean_Area(fs * 6 + fs * 4 + fs * 5 + x_start, y_start, fs * 6, fs, 0x00C8EBFA);
        }
        if (flag != -1)
        {
            kl_sort(head_global, flag);
            refresh_data(pic_list);
            f_tmp = 1; // 重新加载函数的状态码
            flag = -1;
        }
    }

    // 显示中英文（1倍字体：16*16）
    Display_characterX(x_start, y_start, (unsigned char *)str, 0xFF0000, 2); // 64*64
    free(str);
    free(tmp);

}

// 图片滑动变化变换
void image_sliding_transform(int ts_fd, char (*pic_list)[256], int pic_size)
{
    int x_tmp = 0, y_tmp = 0, i = 0, tmp = 0;
    while (1)
    {
        // 2.读取触摸屏数据
        getxy(ts_fd, &x_tmp, &y_tmp);
        // printf("(%d, %d)\n", x_tmp, y_tmp);
        //触摸屏按下
        if (touch_data.type == EV_KEY && touch_data.code == BTN_TOUCH && touch_data.value == 1)
        {
            tmp = x_tmp;
            select_sort(x_tmp, y_tmp, pic_list);
        }
        //触摸屏松开
        if (touch_data.type == EV_KEY && touch_data.code == BTN_TOUCH && touch_data.value == 0)
        {

            if (x_tmp - tmp < 0)
                i--; // 点击左边上一张
            else if (x_tmp - tmp > 0)
                i++; //点击右边下一张
            if (i < 0)
                i = pic_size;
            // show_pic_full(pic_list[i % pic_size]);
            jpg_trans(pic_list[i % pic_size]);
            select_sort(x_tmp, y_tmp, pic_list);
            x_tmp = 0;
            y_tmp = 0;
        }
        if (f_tmp == 1)
            break;
    }

}

// 图片点击变换
void image_transform(int ts_fd, char (*pic_list)[256], int pic_size, unsigned int *fb_l)
{
    int x_tmp = 0, y_tmp = 0, i = 0;
    while (1)
    {
        // 2.读取触摸屏数据
        getxy(ts_fd, &x_tmp, &y_tmp);
        printf("(%d, %d)\n", x_tmp, y_tmp);
        //已点击松开前的那个坐标才能为准
        if (touch_data.type == EV_KEY && touch_data.code == BTN_TOUCH && touch_data.value == EV_SYN)
        {

            if (x_tmp <= 400 && x_tmp > 0)
                i--; // 点击左边上一张
            else if (x_tmp <= 800 && x_tmp > 400)
                i++; //点击右边下一张
            if (i < 0)
                i = pic_size;
            show_pic_full(pic_list[i % pic_size], fb_l);
            x_tmp = 0;
            y_tmp = 0;
        }
    }
}

//获取点击x,y坐标轴
void getxy(int ts_fd, int *x, int *y)
{

    bzero(&touch_data, sizeof(touch_data));
    read(ts_fd, &touch_data, sizeof(touch_data));
    if (touch_data.type == EV_ABS)
    {
        if (touch_data.code == ABS_X)
            *x = touch_data.value;
        if (touch_data.code == ABS_Y)
            *y = touch_data.value;
        if (*x != 0 && *y != 0)
        {
            *x = (*x) * 800 / 1024;
            *y = (*y) * 480 / 600;
        }
    }
}

// 打开linux 的linux文件
int open_file(char *path)
{
    int lcd_fd = open(path, O_RDWR); //打开文件
    if (lcd_fd == -1)            //判断lcd_fd是否等于-1,等于（打开失败）
    {
        //打开失败输出open failed
        fprintf(stderr, "[%d]: open failed: %s\n", __LINE__, strerror(errno));
        // exit(1);
        return 1;
    }

    return lcd_fd;
}

/**
 * @brief 全屏显示图片
 * 
 * @param path 
 */
void show_pic_full(char *path, unsigned int *fb_l)
{
    int img_fi;
    img_fi = open_file(path);
    // 3.读取源文件到,显存，显示颜色
    read(img_fi, fb_l, 800 * 480 * 4);
    close(img_fi);
}

/**
 * @brief 显示颜色
 * 
 * @param color 颜色
 * @param x_start x轴起始
 * @param y_start y轴起始
 * @param w 宽
 * @param h 高
 */ 
void show_color(unsigned int color, int x_start, int y_start, int w, int h, unsigned int *fb_l)
{
    int x, y;
    for (y = y_start; y < y_start + h; y++)
        for (x = x_start; x < x_start + w; x++)
            *(fb_l + x + 800 * y) = color;
}

/**
 *   2.映射显存 
 * @param lcd_fd 映射的文件描述符
 * @param fb_l 映射区的内存起始地址
*/
unsigned int * mem_map(int lcd_fd)
{
    unsigned int * fb_l = mmap(NULL,                   // 指定映射的地址（一般填NULL，由系统随机分配）
              FB_SIZE,          // 内存的大小（开发板屏幕4*800*480字节）
              PROT_READ | PROT_WRITE, // 保护权限（PROT_READ|PROT_WRITE）
              MAP_SHARED,             // 共享的	MAP_SHARED
              lcd_fd,                 // 映射的文件描述符
              0);                     // 映射后偏移量（一般填0，不偏移）
    if (fb_l == MAP_FAILED)
    { 
        printf("%d : mem map fialed\n", __LINE__ );
    }
    return fb_l;
}

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



// jpg图像转换rgb数据
void write_trans(unsigned long (*image)[WIDTH], unsigned char *bmp_buffer, 
                struct image_info *imageinfo, struct fb_var_screeninfo *vinfo)
{

    int x, y, i = 0;
    for (x = 0; x < vinfo->yres && x < imageinfo->height; x++)
    {
        for (y = 0; y < vinfo->xres && y < imageinfo->width; y++)
        {
            // unsigned long lcd_offset = (vinfo->xres * x + y) * 4;
            unsigned long bmp_offset = (imageinfo->width * x + y) * imageinfo->pixel_size;

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

/**
 * @brief 显示jpg图片
 * 
 * @param filepath jpg图片路径
 * @return int 
 */
int jpg_trans(char * filepath)
{
    // 读取图片文件属性信息
    // 并根据其大小分配内存缓冲区jpg_buffer
    struct stat file_info;

    if (stat(filepath, &file_info) == -1)
    {
        fprintf(stderr, "[%d]: stat failed: %s\n", __LINE__, strerror(errno));
        exit(1);
    }

    int fd = open_file(filepath);

    unsigned char *jpg_buffer;
    jpg_buffer = (unsigned char *)calloc(1, file_info.st_size);
    read_image_from_file(fd, jpg_buffer, file_info.st_size);

    // 声明解压缩结构体，以及错误管理结构体
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    // 使用缺省的出错处理来初始化解压缩结构体
    cinfo.err = jpeg_std_error(&jerr);
    // cinfo.jpeg_common_fields->err;
    jpeg_create_decompress(&cinfo);

    // 配置该cinfo，使其从jpg_buffer中读取jpg_size个字节
    // 这些数据必须是完整的JPEG数据
    jpeg_mem_src(&cinfo, jpg_buffer, file_info.st_size);

    // 读取JPEG文件的头，并判断其格式是否合法
    int ret = jpeg_read_header(&cinfo, true);
    if (ret != 1)
    {
        fprintf(stderr, "[%d]: jpeg_read_header failed:  %s\n",
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

    // 循环地将图片的每一行读出并解压到bmp_buffer中 
    while (cinfo.output_scanline < cinfo.output_height)
    {
        unsigned char *buffer_array[1];
        buffer_array[0] = bmp_buffer + (cinfo.output_scanline) * row_stride;
        jpeg_read_scanlines(&cinfo, buffer_array, 1);
    }

    // 解压完了，将jpeg相关的资源释放掉
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    free(jpg_buffer);
    close(fd);

    show_img(bmp_buffer, &imageinfo);
    return 0;
}

void show_img(unsigned char *bmp_buffer, struct image_info *imageinfo)
{
    // 准备LCD屏幕
    int lcd = open_file("/dev/fb0");

    // 获取LCD设备的当前参数
    struct fb_var_screeninfo vinfo;
    ioctl(lcd, FBIOGET_VSCREENINFO, &vinfo);

    
    unsigned long bpp = vinfo.bits_per_pixel;
    unsigned long(*FB)[WIDTH];
    // 根据当前LCD设备参数申请一块适当大小的 frame-buffer，映射到 LCD
    int lcd_size = vinfo.xres * vinfo.yres * bpp / 8;
    FB = mmap(NULL, lcd_size,
              PROT_READ | PROT_WRITE, MAP_SHARED, lcd, 0);

    
    unsigned long(*image)[WIDTH] = calloc(SCREEN_SIZE, 4);

    write_trans(image, bmp_buffer, imageinfo, &vinfo);
    
    free(bmp_buffer); //rgb数据已转换出来,释放申请内存
    printf("%lx \n", *image[200]);
    // 将image中的RGB图像数据，写入LCD的FRAMEBUFFER中
    falling_down_in(FB, image);

    free(image);
    munmap(FB, lcd_size); //解除映射
    close(lcd);

}


