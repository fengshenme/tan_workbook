
#include <stdio.h>
#include <jpeglib.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

unsigned int *FB;
int lcd_fd;
int FBShowLine(int w, int h, unsigned char *buffer);
int FBInit();

int write_jpeg_file(const char *jpeg_file, unsigned char *rgb_buffer, int width, int height, int quality)
{
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    int row_stride = 0;
    FILE *fp = NULL;
    JSAMPROW row_pointer[1];

    cinfo.err = jpeg_std_error(&jerr);

    jpeg_create_compress(&cinfo);

    fp = fopen(jpeg_file, "wb");
    if (fp == NULL)
    {
        printf("open file %s failed.\n", jpeg_file);
        return -1;
    }
    jpeg_stdio_dest(&cinfo, fp);
    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3; // rgb
    cinfo.in_color_space = JCS_RGB; //设置输入格式

    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, quality, 1); // todo 1 == true
    jpeg_start_compress(&cinfo, TRUE);
    row_stride = width * cinfo.input_components;

    while (cinfo.next_scanline < cinfo.image_height)
    {
        row_pointer[0] = &rgb_buffer[cinfo.next_scanline * row_stride];
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);
    fclose(fp);

    return 0;
}
unsigned char rgb_buffer[800*480*3];
int subs;
int main(int argc, char **argv)
{
    subs = 0;
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;
    int row_stride;
    unsigned char *buffer;

    if (argc != 2)
    {
        printf("Usage: \n");
        printf("%s <jpg_file>\n", argv[0]);
        return -1;
    }

    FBInit();

    // 分配和初始化一个decompression结构体
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);

    // 指定源文件
    if ((infile = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "can't open %s\n", argv[1]);
        return -1;
    }
    jpeg_stdio_src(&cinfo, infile);

    // 用jpeg_read_header获得jpg信息
    jpeg_read_header(&cinfo, TRUE);
    /* 源信息 */
    printf("image_width = %d\n", cinfo.image_width);
    printf("image_height = %d\n", cinfo.image_height);
    printf("num_components = %d\n", cinfo.num_components);

    // 设置解压参数,比如放大、缩小
    printf("enter scale M/N:\n");
    scanf("%d/%d", &cinfo.scale_num, &cinfo.scale_denom);
    printf("scale to : %d/%d\n", cinfo.scale_num, cinfo.scale_denom);

    // 启动解压：jpeg_start_decompress
    jpeg_start_decompress(&cinfo);

    /* 输出的图象的信息 */
    printf("output_width = %d\n", cinfo.output_width);
    printf("output_height = %d\n", cinfo.output_height);
    printf("output_components = %d\n", cinfo.output_components); //解压的是rgb，故为3元素

    // 一行的数据长度
    row_stride = cinfo.output_width * cinfo.output_components;
    buffer = malloc(row_stride); //分配空间用来存储一行数据

    // 循环调用jpeg_read_scanlines来一行一行地获得解压的数据
    while (cinfo.output_scanline < cinfo.output_height)
    {
        (void)jpeg_read_scanlines(&cinfo, &buffer, 1);

        // 写到LCD去
        FBShowLine(cinfo.output_width, cinfo.output_scanline, buffer); //一行行的将数据写到LCD上去
    }
    


    
    char des[30];
    sprintf(des,"ab%s", argv[1]);
   if( write_jpeg_file(des, rgb_buffer, 800, 480, 60) == 0) //宽800, 高480 压缩率90
     printf("success \n");

    free(buffer);
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);

    munmap(FB, 800*480*4);
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

int FBShowLine(int w, int h, unsigned char *rgb)
{
    int i, j = 0;
     unsigned int argb[w];
    memset(argb, 0, w);
    //左移和位或操作实现数据的拼接 由rgb转为ARGB
    for (i = 0; j < w; i += 3, j++)
    {
        argb[j] = 0x00 << 24 | rgb[i] << 16 | rgb[i + 1] << 8 | rgb[i + 2];
    }
    int cou = w*3;
    memcpy(&rgb_buffer[subs], rgb, cou);
    subs+=cou;
    //  fprintf(stderr, "%d--%d\n", __LINE__, w);

    memcpy(&FB[800 * (h - 1)], argb, w * 4);

    return 0;
}