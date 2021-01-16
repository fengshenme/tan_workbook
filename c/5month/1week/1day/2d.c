#include <stdio.h>
#include <jpeglib.h> //包含jpg库的头文件
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

unsigned int *FB;
int lcd_fd;

int FBInit();
int FBShowLine(int w, int h, unsigned char *rgb, int x);

int main(int argc, const char *argv[])
{

    FBInit();
    int i;
    //定义解压缩结构体变量和保存出错信息的结构体变量,并初始化这两个变量
    struct jpeg_decompress_struct mydecom;
    jpeg_create_decompress(&mydecom);
    struct jpeg_error_mgr myerr;
    mydecom.err = jpeg_std_error(&myerr);

    if (argc != 2)
    {
        printf("usage :%s <jpeg_path>", argv[0]);
    }

    //指定解压缩数据源
    FILE *myfile = fopen(argv[1], "r+");
    if (myfile == NULL)
    {
        perror("打开jpg图片失败!\n");
        return -1;
    }
    jpeg_stdio_src(&mydecom, myfile);

    //读取jpg图片的头信息
    jpeg_read_header(&mydecom, true);

 

    //打印图片的属性信息
    printf("图片原始宽：%d\n", mydecom.image_width);
    printf("图片原始高：%d\n", mydecom.image_height);

        // 设置解压参数,比如放大、缩小
    printf("设置缩放比例 M/N:\n");
    scanf("%d/%d", &mydecom.scale_num, &mydecom.scale_denom); while(getchar() != '\n');
    printf("缩放后图片宽：%d \n", mydecom.output_width);
    printf("缩放后图片高：%d \n", mydecom.output_height);

    int x, y = 0;
    // 设置显示位置
    printf("显示位置 x-y:\n");
    scanf("%d-%d", &x, &y); while(getchar() != '\n');
    printf("设置起始坐标: (%d, %d)\n", x, y);

       //开始解压缩
    jpeg_start_decompress(&mydecom);

    unsigned char *buf = malloc(mydecom.image_width / mydecom.scale_denom * 3);
    //读取你刚才解压的jpg原始数据，然后填充到开发板的液晶屏上
    for (i = y; i < mydecom.image_height/mydecom.scale_denom + y; i++)
    {
        jpeg_read_scanlines(&mydecom, &buf, 1); //一次读取一行数据，存放到buf中
        //立马把读取到的一行RGB(ARGB)数据填充到液晶屏
        FBShowLine(mydecom.image_width/mydecom.scale_denom, i, buf , x);
    }

    // jpeg完成解压-释放解压
    jpeg_finish_decompress(&mydecom);
    jpeg_destroy_decompress(&mydecom);


    fclose(myfile);
    close(lcd_fd);
    
    return 0;
}

int FBInit()
{
    lcd_fd = open("/dev/fb0", O_RDWR); //打开LCD文件
    if (lcd_fd == -1)                  //判断lcd_fd是否等于-1,等于（打开失败）
    {
        perror("open lcd failed"); //打开失败输出open failed
        return 1;
    }

    FB = mmap(NULL,                   // 指定映射的地址（一般填NULL，由系统随机分配）
              800 * 480 * 4,          // 内存的大小（开发板屏幕4*800*480字节）
              PROT_READ | PROT_WRITE, // 保护权限（PROT_READ|PROT_WRITE）
              MAP_SHARED,             // 共享的	MAP_SHARED
              lcd_fd,                 // 映射的文件描述符
              0);                     // 映射后偏移量（一般填0，不偏移）
    return 0;
}
// 800 480   400 240
int FBShowLine(int w, int h, unsigned char *rgb, int x)
{
    int i, j = 0;
    unsigned int argb[w];
    memset(argb, 0, w);
    //左移和位或操作实现数据的拼接 由rgb转为ARGB
    for (i = 0; j < w; i += 3, j++)
    {
        argb[j] = 0x00 << 24 | rgb[i] << 16 | rgb[i + 1] << 8 | rgb[i + 2];
    }
    if(h <= 1 || h >= 479)
        fprintf(stderr, "%d--%d\n", __LINE__, h);
    memcpy(&FB[800 * h + x], argb, w * 4);

    return 0;

}