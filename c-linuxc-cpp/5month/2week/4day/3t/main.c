#include <stm32f4xx.h>
#include <led.h>
#include <beep.h>
#include <key.h>
#include <exti.h>
#include <systick.h>

int main(void)
{


	
	//使用定时器进行 延时
	led_init();
	systick_init();
	
	led_onoff(1, 0);
	led_onoff(2, 1);
	led_onoff(3, 1);
	led_onoff(4, 1);
	
	while(1)
	{
		led_onoff(1, 0);
		delay_s(10);
		led_onoff(1, 1);
		delay_s(10);
	
	}
	
	return 0;
}
