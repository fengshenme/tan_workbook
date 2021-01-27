#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// 如何才能在开发板屏幕上显示颜色？
// ---》把大象塞进冰箱，分几步？
// 1.打开冰箱门	---》打开LCD文件。”/dev/fb0”	open
// 2.把大象塞进去	---》将颜色写入到LCD中		write
// 3.关闭冰箱门	---》关闭LCD文件				close
// 冰箱：LCD屏幕
// 大象：颜色数据

/******************主函数***********************/
int main(int argc, char const *argv[])
{
	// 1.打开冰箱门	---》打开LCD文件。”/dev/fb0”	
	int lcd_fd;
	lcd_fd = open("/dev/fb0", O_RDWR);
	if(lcd_fd == -1)
	{
		perror("open lcd failed");
		return 1;
	}

	// 2.把大象塞进去	---》将颜色写入到LCD中	
	unsigned int color_red = 0x00FF0000;

	// 尝试使用循环，显示更多的位置，直至全屏
	for (size_t i = 0; i < 800*480; i++)
	{
		write(lcd_fd, &color_red, 4);
	}
	
	

	// 3.关闭冰箱门	---》关闭LCD文件				
	close(lcd_fd);


	return 0;
}