#include <stm32f4xx.h>
#include <led.h>
#include <beep.h>
#include <key.h>

int main(void)
{

	key_init();
	led_init();
	beep_init();

	delay(500);

	// beep_onoff(1);
	
	int aflag = 0;
	int eflag = 0;
	
	//闪烁 GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)
	while (1)
	{

		// display();

		//GPIO_TypeDef GPIOa;
		//延时

		if (GPIOA->IDR & 0x1)
		{
		
			aflag = aflag == 0 ? 1 : 0;
			
		if(aflag == 1)
		{
			led_onoff(1, 1);
		}
		if(aflag == 0)
		{
			led_onoff(1, 0);
		}
			
		}
		

		
		if (PEin(2))
		{
			led_onoff(2, 1);
			eflag = eflag == 0 ? 1 : 0;
		}
		else
		{
			led_onoff(2, 0);
		}
		if (GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3))
		{
			led_onoff(3, 1);
		}
		else
		{
			led_onoff(3, 0);
		}
	}

	return 0;
}
