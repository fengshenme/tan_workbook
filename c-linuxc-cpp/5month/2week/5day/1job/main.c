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
#include <stm32f4xx.h>
#include <beep.h>
#include <exti.h>
#include <systick.h>
#include <timer.h>
#include <key.h>

int main(void)
{
		//优先级2:2
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	led_init();
	beep_init();
	//key_init();
	exti_init();
	u_systick_init();
	timer_init();
	//key_init();
	
	//key_led();
	
	while(1){

	}
	
	return 0;
}
