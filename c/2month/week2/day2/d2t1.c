/**
 *
 * @file main.c
 * @author tan wei feng (1015956962@163.com)
 * @brief 基于ARM平台的电子相册, 已完成手指滑动切换,递归检索，可检索低层的所有子目录
 * @version 0.2
 * @date 2020-10-26
 *
 * todo 筛选功能, 图片切换功能, 更多的图片切换效果
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../include/maina.h"

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

} img_kl, *img_pt;

img_pt kl_init(void);
int kl_img_add(img_pt n_img, img_pt head);
bool isdir(const char *pathname);

/**
 * 查找目录下文件ebm
 * @param name 查找目录名
 * @param f_suffix 文件后缀名
 */
int find_file(const char *name, img_pt head, char *f_suffix);

// *全局变量
unsigned int *FB;              // 映射显存
struct input_event touch_data; // 触摸屏结构体
unsigned int i_count;          //找到的数量

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
 */
void dir_proc(const char * i_path, char * des_path);

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

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <dir>\n", argv[0]);
        exit(1);
    }

     char (*pic_list)[256] = calloc(20, 256);
    if (pic_list == NULL)
    {
        perror("calloc failed");
        return 1;
    }
    bzero(pic_list, 20 * 256);

    char * path_ac = malloc(256);
    bzero(path_ac, 256);

    dir_proc(argv[1], path_ac);
     img_pt head = kl_init();
    int pic_size = find_file(path_ac, head, ".ebm");
    printf("%d -a-\n", pic_size);
    struct list_head *pos;
    int i = 0;
    list_for_each(pos, &head->list)
    {
        img_pt get_node = list_entry(pos, img_kl, list);

        strcpy(pic_list[i], get_node->path);

        i++;
        printf("%s\n", get_node->path);
        printf("%s\n",  get_node->name);
        printf("%d\n",  get_node->size);
        printf("%s\n",  asctime(gmtime(&get_node->c_time)) );
    }
    free(path_ac);

    // 1.打开触摸屏文件
    int ts_fd = open_file("/dev/input/event0"); // 触摸屏设备文件描述符
    int lcd_fd = open_file("/dev/fb0");         //lcd设备文件描述符

    // 2.映射显存/dev/input/event0
    mem_map(lcd_fd);
    // 3.图片点击切换
    // image_transform(ts_fd, pic_list, pic_size);
    // 3.图片滑动切换
    image_sliding_transform(ts_fd, pic_list, i_count);

    munmap(FB, 800 * 480 * 4); //解除映射
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
int find_file(const char *name, img_pt head, char *f_suffix)
{
    DIR *mydir;
    mydir = opendir(name);
    struct dirent *dir_info;
    int i_count=0;
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

        char *path_o = malloc(256);

        sprintf(path_o, "%s/%s", name, f_name);
        int len = strlen(f_name);
        if (!strcmp(f_name + len - strlen(f_suffix), f_suffix))
        {

            img_pt n_img = malloc(sizeof(img_kl));
            if (n_img == NULL)
            {
                printf("img_node malloc fialed!!\n");
                return -1;
            }

            strcpy(n_img->path, path_o);

            struct stat file_info;
            stat(n_img->path, &file_info);
            n_img->name = f_name;
            n_img->size = file_info.st_size;
            n_img->c_time = file_info.st_ctime;
            kl_img_add(n_img, head);

            i_count++;
        }
        if (isdir(path_o))
        {
            i_count += find_file(path_o, head, f_suffix);
        }
        free(path_o);
    }

    closedir(mydir);
    return i_count;
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

// 图片滑动变化变换
void image_sliding_transform(int ts_fd, char (*pic_list)[256], int pic_size)
{
    int x_tmp = 0, y_tmp = 0, i = 0, tmp = 0;
    while (1)
    {
        // 2.读取触摸屏数据
        getxy(ts_fd, &x_tmp, &y_tmp);
        printf("(%d, %d)\n", x_tmp, y_tmp);
        //已点击松开前的那个坐标才能为准
        if (touch_data.type == EV_KEY && touch_data.code == BTN_TOUCH && touch_data.value == 1)
        {
            tmp = x_tmp;
        }
        if (touch_data.type == EV_KEY && touch_data.code == BTN_TOUCH && touch_data.value == 0)
        {

            if (x_tmp - tmp < 0)
                i--; // 点击左边上一张
            else if (x_tmp - tmp > 0)
                i++; //点击右边下一张
            if (i < 0)
                i = pic_size;
            show_pic_full(pic_list[i % pic_size]);
            x_tmp = 0;
            y_tmp = 0;
        }
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

// 输入目录处理
void dir_proc(const char * i_path, char * des_path)
{
    if (!isdir(i_path)) // 判断输入参数是否为目录
    {
        printf("Not a directory\n");
        exit(1);
    }
    
    char *last_str;
    const char *str_tmp;
    if(*(strrchr(i_path, '\0')-1) == '/')
    {
        *(strrchr(i_path, '/')) = '\0';
    }
    last_str = strrchr(i_path, '/');
    str_tmp = last_str == 0 ? i_path : last_str +1;
     
    getcwd(des_path, 256);
    strcat(des_path, "/");
    strcat(des_path, str_tmp);
}


img_pt kl_init()
{
    img_pt n_img = malloc(sizeof(img_kl));
    if (n_img == NULL)
    {
        printf("img_node malloc fialed!!\n");
        return NULL;
    }

    n_img->list.next = &n_img->list;
    n_img->list.prev = &n_img->list;
    return n_img;
}

int kl_img_add(img_pt n_img, img_pt head)
{

    list_add(&n_img->list, &head->list);

    return 0;
}
