#ifndef _MAIN_H_
#define _MAIN_H_


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h>

#include <sys/mman.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "list.h"

// *全局变量
unsigned int *FB;              // 映射显存
struct input_event touch_data; // 触摸屏结构体

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
*/
void mem_map(int lcd_fd);

/**
 * @brief 输入目录处理
 * 
 * @param i_path 
 * @param des_path 
 * @return 0:成功 1:失败
 */
int dir_proc(const char * i_path, char * des_path);

/**
 * @brief 图片显示
 * 
 * @param path 
 */
void show_pic_full(char *path);

/**
 * @brief 显示颜色
 * 
 * @param color 颜色
 * @param x_start x轴起始
 * @param y_start y轴起始
 * @param w 宽
 * @param h 高
 */
void show_color(unsigned int color, int x_start, int y_start, int w, int h);

/**
 * @brief 图片点击变换
 * 
 * @param ts_fd 
 * @param pic_list 
 * @param pic_size 
 */
void image_transform(int ts_fd, char (*pic_list)[256], int pic_size);
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
int get_img(char (*pic_list)[256], char * path_ac);

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

#endif 
