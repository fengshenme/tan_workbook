//              GND   电源地
//              VCC   接5V或3.3v电源
//              SCL   接PB13（SCL）
//              SDA   接PB15（SDA）
//              RES   接PB11 如果是用4针iic接口这个脚可以不接
//////////////////////////////////////////////////////////////////////////////////

#include <delay.h>
#include <sys.h>
#include <oled.h>
#include <led.h>
#include <bmp.h>
#include <stm32f4xx.h>


int main(void)
{
	u8 t;
	delay_init();		  //延时函数初始化
	// NVIC_Configuration(); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
						  //		delay_ms(8000);
	OLED_Init();		  //初始化OLED
	OLED_Clear();
	
	
	
	led_init();
	led_onoff(1, 1);
	led_onoff(2, 1);
	led_onoff(3, 1);
	led_onoff(4, 0);

	t = ' ';

	while (1)
	{
		OLED_Clear();
		OLED_ShowCHinese(0, 0, 0);	 
		OLED_ShowCHinese(18, 0, 1);	 
		OLED_ShowString(6, 3, "0.96' OLED TEST", 16);
		//OLED_ShowString(8,2,"ZHONGJINGYUAN");
		//	OLED_ShowString(20,4,"2014/05/01");
		OLED_ShowString(0, 6, "ASCII:", 16);
		OLED_ShowString(63, 6, "CODE:", 16);
		OLED_ShowChar(48, 6, t, 16); //显示ASCII字符
		t++;
		if (t > '~')
			t = ' ';
		OLED_ShowNum(103, 6, t, 3, 16); //显示ASCII字符的码值
		delay_ms(8000);
		delay_ms(8000);

		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		OLED_DrawBMP(0, 0, 128, 8, BMP1); //图片显示(图片显示慎用，生成的字表较大，会占用较多空间，FLASH空间8K以下慎用)
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		OLED_DrawBMP(0, 0, 128, 8, BMP1);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
		delay_ms(8000);
	}
}
