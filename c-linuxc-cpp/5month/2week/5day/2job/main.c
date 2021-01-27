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

int main(void)
{
	//优先级2:2
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	led_init();
	//beep_init();
	//key_init();
	//exti_init();
	u_systick_init();
	//timer2_init();
	//key_init();

	//key_led();

	led_onoff(1, 1);
	led_onoff(2, 1);
	led_onoff(3, 1);
	led_onoff(4, 1);

	oled_test();

	pwm_init();
	int count = 0;

	while (1)
	{

		//比较值1000->0
		//0->1000
		//每次修改要延时
		while (count < 1000)
		{
			TIM_SetCompare4(TIM1, count++);

			// TIM_CtrlPWMOutputs

			u_delay_ms(1);
		}
		u_delay_ms(100);
		while (count > 0)
		{
			TIM_SetCompare4(TIM1, count--);
			u_delay_ms(1);
		}

		u_delay_ms(100);
	}

	return 0;
}
