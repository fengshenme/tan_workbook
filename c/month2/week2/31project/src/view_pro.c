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
#include "../include/font_show.h"

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

    // 2.映射显存/dev/input/event0
    mem_map(lcd_fd);
    // 3.图片点击切换
    // image_transform(ts_fd, pic_list, pic_size);
    while(1)
    {
        // 3.图片滑动切换
        image_sliding_transform(ts_fd, pic_list, pic_size);
        f_tmp = 0;
    }

    munmap(FB, 800 * 480 * 4); //解除映射
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
    // 初始化字体库
    Init_Font();

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

    // 关闭字体库
    UnInit_Font();
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
            show_pic_full(pic_list[i % pic_size]);
            select_sort(x_tmp, y_tmp, pic_list);
            x_tmp = 0;
            y_tmp = 0;
        }
        if (f_tmp == 1)
            break;
    }

}

// 图片点击变换
void image_transform(int ts_fd, char (*pic_list)[256], int pic_size)
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
            show_pic_full(pic_list[i % pic_size]);
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
    int lcd_fd;                  //定义变量
    lcd_fd = open(path, O_RDWR); //打开文件
    if (lcd_fd == -1)            //判断lcd_fd是否等于-1,等于（打开失败）
    {
        perror("open lcd failed"); //打开失败输出open failed
        return 1;
    }
    return lcd_fd;
}

/**
 * @brief 全屏显示图片
 * 
 * @param path 
 */
void show_pic_full(char *path)
{
    int img_fi;
    img_fi = open_file(path);
    // 3.读取源文件到,显存，显示颜色
    read(img_fi, FB, 800 * 480 * 4);
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
void show_color(unsigned int color, int x_start, int y_start, int w, int h)
{
    int x, y;
    for (y = y_start; y < y_start + h; y++)
        for (x = x_start; x < x_start + w; x++)
            *(FB + x + 800 * y) = color;
}

/**
 *   2.映射显存 
 * @param lcd_fd 映射的文件描述符
*/
void mem_map(int lcd_fd)
{
    FB = mmap(NULL,                   // 指定映射的地址（一般填NULL，由系统随机分配）
              800 * 480 * 4,          // 内存的大小（开发板屏幕4*800*480字节）
              PROT_READ | PROT_WRITE, // 保护权限（PROT_READ|PROT_WRITE）
              MAP_SHARED,             // 共享的	MAP_SHARED
              lcd_fd,                 // 映射的文件描述符
              0);                     // 映射后偏移量（一般填0，不偏移）
    if (FB == MAP_FAILED)
        perror("mem map fialed\n");
    return;
}