/**
 *
 * @file main.c
 * @author tan wei feng (1015956962@163.com)
 * @brief 基于ARM平台的电子相册, 已完成手指滑动切换,递归检索，可检索低层的所有子目录
 * @version 0.3
 * @date 2020-10-27
 *
 * todo 筛选功能, 图片切换功能, 更多的图片切换效果
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../include/main.h"


int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <dir>\n", argv[0]);
        exit(1);
    }

    char * path_ac = malloc(256);

    if(!dir_proc(argv[1], path_ac))
    {
        printf("shift dir fialed!\n");
    }
    head_global = kl_init(); // 初始化全局的链表
    // 开辟连续堆空间 30个
    char (*pic_list)[256] = calloc(30, 256);
    int pic_size = 0;

    pic_size = get_img(pic_list, path_ac);
    if (pic_size == -1)
    {
        printf("get file data fialed!\n");
    }

    if(!view_init(pic_list,  pic_size))
    {
        printf("view init fialed!\n");
    }
    
    free(path_ac);
    free(pic_list);

    return 0;
}

