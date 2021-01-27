
#include <delay.h>
#include <sys.h>
#include <oled.h>
#include <led.h>
#include <bmp.h>
#include <stm32f4xx.h>

int main(void)
{
	u8 t;
	delay_init(); //延时函数初始化
	// NVIC_Configuration(); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	//		delay_ms(8000);
	OLED_Init(); //初始化OLED
	OLED_Clear();

	led_init();
	led_onoff(1, 1);
	led_onoff(2, 1);
	led_onoff(3, 1);
	led_onoff(4, 0);

	t = ' ';
	OLED_DrawBMP(0, 0, 128, 8, BMP1);
	OLED_ShowCHinese(0, 0, 0);
	OLED_ShowCHinese(18, 0, 1);


	return 0;
}
