#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <syslog.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>
#include <pthread.h>

#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>

#include <linux/input.h>
#include <linux/fb.h>
// 多路复用
#include <sys/select.h>
#include <sys/time.h>

#include "list.h"
#include "jpeglib.h"
#include "font_show.h"

#define SCREEN_SIZE 800 * 480
#define FB_SIZE 800 * 480 * 4
#define WIDTH 800
#define HEIGHT 480
#define BLIND 5 //百叶窗的页数

// *全局变量

struct input_event touch_data; // 触摸屏结构体

struct argument
{
    unsigned long (*FB)[WIDTH];
    unsigned long (*image)[WIDTH];
    int offset;
    int flag;
};

struct image_info
{
    int width;
    int height;
    int pixel_size;
};

typedef struct img_node
{
    //* 数据域
    //文件绝对路径
    char path[256];
    //文件名
    char *name;
    //文件大小
    int size;
    // 文件创建时间
    time_t c_time;

    //*指针域
    struct list_head list;

} kl_img, *kl_pt;

kl_pt head_global; //全局的链表的头

/**
 * @brief 初始化链表
 * 
 * @return kl_pt 
 */
kl_pt kl_init(void);

/**
 * @brief 插入节点n_img到head之后
 * 
 * @param n_img 
 * @param head 
 * @return int 
 */
int kl_img_add(kl_pt n_img, kl_pt head);

/**
 * 查找目录下文件ebm
 * @param name 查找目录名
 * @param f_suffix 文件后缀名
 */
int find_file(const char *name, kl_pt head, char *f_suffix);

/**
 * @brief 打开linux 的linux文件
 * 
 * @param path 
 * @return int 
 */
int open_file(char *path);

//获取点击的x,y坐标轴
void getxy(int lcd_fd, int *x_tmp, int *y_tmp);

/**
 *   2.映射显存 
 * @param lcd_fd 映射的文件描述符
 * @return fb_l 映射显存的起始地址
*/
unsigned int *mem_map(int lcd_fd);

/**
 * @brief 输入目录处理
 * 
 * @param i_path 
 * @param des_path 
 * @return 0:成功 1:失败
 */
int dir_proc(const char *i_path, char *des_path);

/**
 * @brief 图片显示
 * 
 * @param path 图片路径
 * @param fb_l 映射内存起始地址
 */
void show_pic_full(char *path, unsigned int *fb_l);

/**
 * @brief 显示颜色
 * 
 * @param color 颜色
 * @param x_start x轴起始
 * @param y_start y轴起始
 * @param w 宽
 * @param h 高
 * @param fb_l 映射内存起始地址
 * 
 */
void show_color(unsigned int color, int x_start, int y_start, int w, int h, unsigned int *fb_l);

/**
 * @brief 图片点击变换
 * 
 * @param ts_fd 
 * @param pic_list 
 * @param pic_size 
 */
void image_transform(int ts_fd, char (*pic_list)[256], int pic_size, unsigned int *fb_l);

/**
 * @brief 图片滑动变化变换
 * 
 * @param ts_fd 
 * @param pic_list 
 * @param pic_size 
 */
void image_sliding_transform(int ts_fd, char (*pic_list)[256], int pic_size);

/**
 * @brief 检测是否为目录 
 * 
 * @param pathname 
 * @return true 
 * @return false 
 */
bool isdir(const char *pathname);

/**
 * @brief 视图模块初始化
 * 
 * @param pic_list 存储文件绝对路径的数组
 * @param pic_size 目录下扫描出的文件总数
 * @return int  0: 成功 1: 失败
 * 
 */
int view_init(char (*pic_list)[256], int pic_size);

/**
 * @brief 获取file数据存入链表中,将文件路径存入数组中
 * 
 * @param pic_list 将存储文件绝对路径的数组
 * @param path_ac 目录绝对路劲
 * @return int -1:失败 
 */
int get_img(char (*pic_list)[256], char *path_ac);

/**
 * @brief 排序
 * 
 * @param head 需要排序的链表
 * @param select 排序的选项 1: //根据文件名首字母排序
 *                      2: //根据文件大小排序
 *                      default: //根据时间排序
 */
void kl_sort(kl_pt head, int select);

//刷新数据
int refresh_data(char (*pic_list)[256]);

/**
 * @brief 选择
 * 
 * @param x_tmp x轴坐标
 * @param y_tmp y轴坐标
 */
void select_sort(int x_tmp, int y_tmp, char (*pic_list)[256]);

//   图像显示
/**
 * @brief 显示jpg图片
 * 
 * @param filepath 图片文件路径
 * @param effect 选择显示效果,图片出现的方式
 * @return int 
 */
int jpg_trans(char *filepath, int effect);

/**
 * @brief 显示图片
 * 
 * @param bmp_buffer 存储有一张图片(rgb)数据的数组
 * @param imageinfo 文件详情
 * @param effect 选择显示效果,图片出现的方式
 */
void show_img(unsigned char *bmp_buffer, struct image_info *imageinfo, int effect);

/**
 * @brief 将图片数据进行转换
 * 
 * @param bmp_buffer 
 * @param imageinfo 
 * @param vinfo 
 */
void write_trans(unsigned long (*image)[WIDTH], unsigned char *bmp_buffer,
                 struct image_info *imageinfo, struct fb_var_screeninfo *vinfo);

// 将jpeg文件的压缩图像数据读出，放到jpg_buffer中去等待解压
unsigned long read_image_from_file(int fd, unsigned char *jpg_buffer, unsigned long jpg_size);
/**
 * @brief  从上而下显示图片
 * 
 */
void falling_down_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 从上而下消除图片
 * 
 */
void falling_down_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 图片从上而下掉落，穿过显示屏。
 * 
 */
void falling_down(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 从上而下显示图片
 * 
 */
void floating_up_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 从下而上消除图片
 * 
 */
void floating_up_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 图片上浮穿过显示屏
 * 
 */
void floating_up(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 图片从左往右入
 * 
 */
void left2right_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 图片从左往右出
 * 
 */
void left2right_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 图片从左到右移动
 * 
 */
void left_2_right(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 图片从右往左入
 * 
 */
void right2left_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 图片从右往左出
 * 
 */
void right2left_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 从右往左移动
 * 
 */
void right2left(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 百叶窗图片入效果
 * 
 */
void blind_window_in(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 百叶窗图片出效果
 * 
 */
void blind_window_out(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 百叶窗出入效果
 * 
 */
void blind_window(unsigned long (*FB)[WIDTH], unsigned long (*image)[WIDTH]);

/**
 * @brief 百叶窗一个叶片显示
 * 
 * @param p 
 * @return void* 
 */
void *routine(void *p);

#endif
