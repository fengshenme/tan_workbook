#include "../include/head4animation.h"

struct image_info
{
    int width;
    int height;
    int pixel_size;
};

/**
 * @brief 显示jpg图片
 * 
 * @param filepath 图片文件路径
 * @return int 
 */
int jpg_trans(char * filepath);

/**
 * @brief 显示图片
 * 
 * @param bmp_buffer 
 * @param imageinfo 
 */
void show_img(unsigned char *bmp_buffer, struct image_info *imageinfo);

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

    jpg_trans(argv[1]);


    return 0;
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

int Stat(const char *filename, struct stat *file_info)
{
    int ret = stat(filename, file_info);

    if (ret == -1)
    {
        fprintf(stderr, "[%d]: stat failed: %s\n", __LINE__, strerror(errno));
        exit(1);
    }

    return ret;
}

int Open(const char *filename, int mode)
{
    int fd = open(filename, mode);
    if (fd == -1)
    {
        fprintf(stderr, "[%d]: open failed: %s\n", __LINE__, strerror(errno));
        exit(1);
    }

    return fd;
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
    Stat(filepath, &file_info);
    int fd = Open(filepath, O_RDONLY);

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
    int lcd = Open("/dev/fb0", O_RDWR );

    // 获取LCD设备的当前参数
    struct fb_var_screeninfo vinfo;
    ioctl(lcd, FBIOGET_VSCREENINFO, &vinfo);

    
    unsigned long bpp = vinfo.bits_per_pixel;
    unsigned long(*FB)[WIDTH];
    // 根据当前LCD设备参数申请一块适当大小的 frame-buffer，映射到 LCD
    FB = mmap(NULL, vinfo.xres * vinfo.yres * bpp / 8,
              PROT_READ | PROT_WRITE, MAP_SHARED, lcd, 0);

    
    unsigned long(*image)[WIDTH] = calloc(SCREEN_SIZE, 4);

    write_trans(image, bmp_buffer, imageinfo, &vinfo);
    
    free(bmp_buffer); //rgb数据已转换出来,释放申请内存
    printf("%lx \n", *image[200]);
    // 将image中的RGB图像数据，写入LCD的FRAMEBUFFER中
    falling_down_in(FB, image);

    free(image);
    munmap(FB, SCREEN_SIZE); //解除映射
    close(lcd);

}


