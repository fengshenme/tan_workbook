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
#include <stm32f4xx_tim.h>
#include <beep.h>
#include <exti.h>
#include <systick.h>
#include <timer.h>
#include <key.h>
#include <pwm.h>
#include <ultrasonic.h>
#include <usart.h>

int main(void)
{
	//优先级2:2
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	led_init();
	//beep_init();
	//key_init();
	//exti_init();
	// u_systick_init();
	//timer2_init();
	//key_init();

	//key_led();

	led_onoff(1, 0);
	led_onoff(2, 0);
	led_onoff(3, 1);
	led_onoff(4, 1);
	
	//run_mess("por start..cc");
	oled_test();
	ultrasonic_test();
	//while(1){}

	return 0;
}
