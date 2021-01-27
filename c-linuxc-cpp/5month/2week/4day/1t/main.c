#include <stm32f4xx.h>
#include <led.h>
#include <beep.h>
#include <key.h>
#include <exti.h>
#include <systick.h>

int main(void)
{


	
	//优先级2:2
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	led_init();
	
	led_onoff(1, 1);
	led_onoff(2, 1);
	led_onoff(3, 1);
	led_onoff(4, 1);
	beep_init();
	//key_init();
	exti_init();
	
	
	
	delay(500);

	// beep_onoff(1);

	
	while(1){}
		
	return 0;
}
