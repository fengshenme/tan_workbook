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
	int eflag2 = 0;
	int eflag3 = 0;

	while (1)
	{

		// display();

		

		if (!(GPIOA->IDR & 0x1))
		{
			aflag = aflag == 1 ? 0 : 1;

			if (aflag == 1)
			{
				led_onoff(1, 1);
			}
			else
			{
				led_onoff(1, 0);
			}
			delay(500);
		}
		

		if (!PEin(2))
		{
			eflag2 = eflag2 == 1 ? 0 : 1;
			if (eflag2 == 1)
			{
				led_onoff(2, 1);
			}
			else
			{
				led_onoff(2, 0);
			}
			delay(500);
			
		}
		
		if (!GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_3))
		{
			eflag3 = eflag3 == 1 ? 0 : 1;
			if (eflag3 == 1)
			{

				led_onoff(3, 1);
			}
			else
			{
				led_onoff(3, 0);
			}
			delay(500);
		}
	}

	return 0;
}
