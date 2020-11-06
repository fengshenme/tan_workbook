#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#include <sys/mman.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <sys/types.h>

////全局变量
unsigned int *FB;              // 映射显存
struct input_event touch_data; // 触摸屏结构体

int open_file(char *path);
//获取点击的x,y坐标轴
void getxy(int lcd_fd, int *x_tmp, int *y_tmp);
//映射显存
void mem_map(int lcd_fd);
void show_pic_full(char *path);
//显示颜色
void show_color(unsigned int color, int x_start, int y_start, int w, int h);
//图片变换
void image_transform(int ts_fd, char (*pic_list)[256], int pic_size);

/* 检测是否为目录 */
bool isdir(const char *pathname);

/**
 * 查找目录下文件ebm
 * @param name 查找目录名
 * @param f_suffix 文件后缀名
 */
int find_file(const char *name, char (*pic_list)[256], char *f_suffix);

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <dir>\n", argv[0]);
        exit(1);
    }
    if (!isdir(argv[1]))
    {
        printf("Not a directory\n");
        exit(1);
    }

    char(*pic_list)[256];
    pic_list = calloc(20, 256);
    if (pic_list == NULL)
    {
        perror("calloc failed");
        return 1;
    }
    bzero(pic_list, 20 * 256);

    int pic_size = find_file(argv[1], pic_list, ".c");

        // 1.打开触摸屏文件
    int ts_fd;  // 触摸屏设备文件描述符
    int lcd_fd; //lcd设备文件描述符
    ts_fd = open_file("/dev/input/event0");
    lcd_fd = open_file("/dev/fb0");

    // 2.映射显存/dev/input/event0
    mem_map(lcd_fd);
    // 3.图片切换
    image_transform(ts_fd , pic_list, pic_size);

    munmap(lcd_fd, 800 * 480 * 4); //解除映射
    // 4.关闭触摸屏文件显示文件
    close(lcd_fd);
    close(ts_fd);

    free(pic_list);

    return 0;
}

/**
 * 查找目录下文件ebm
 * @param name 查找目录名
 * @param f_suffix 文件后缀名
 */
int find_file(const char *name, char (*pic_list)[256], char *f_suffix)
{
    DIR *mydir;
    mydir = opendir(name);
    struct dirent *dir_info;
    char abs_path[256];

    int i = 0;
    while (1)
    {
        dir_info = readdir(mydir);
        if (dir_info == NULL)
            break;
        char *f_name;
        f_name = dir_info->d_name;
        //非0即真,字符串比较相同返回0
        if (!strcmp(f_name, ".") || !strcmp(f_name, ".."))
            continue;
        int len = strlen(f_name);

        if (!strcmp(f_name + len - strlen(f_suffix), f_suffix))
        {
            bzero(abs_path, 256);
            sprintf(pic_list[i], "%s/%s", getcwd(abs_path, 256), f_name);
            printf("%s\n", pic_list[i]);
            // printf("文件名:%s \n", f_name);
        }
        i++;
    }
    closedir(mydir);
    return i;
}

/**
 * 判断是否为目录
 * @param pathname 目录名
 * @return bool 
 * */
bool isdir(const char *pathname)
{
    struct stat file_info;
    stat(pathname, &file_info);
    if (S_ISDIR(file_info.st_mode))
    {
        return true;
    }
    else
    {
        return false;
    }
}


// 图片变换
void image_transform(int ts_fd, char (*pic_list)[256], int pic_size)
{
    int x_tmp = 0, y_tmp = 0, i = 0
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
            if(i<0)
                i = pic_size;
            show_pic_full(pic_list[i%pic_size]);
            }
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

//打开linux 的linux文件
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

//显示图片
void show_pic_full(char *path)
{
    int img_fi;
    img_fi = open_file(path);
    // 3.读取源文件到,显存，显示颜色
    read(img_fi, FB, 800 * 480 * 4);
    close(img_fi);
}
//显示颜色
void show_color(unsigned int color, int x_start, int y_start, int w, int h)
{
    int x, y;
    for (y = y_start; y < y_start + h; y++)
        for (x = x_start; x < x_start + w; x++)
            *(FB + x + 800 * y) = color;
}

//  2.映射显存
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