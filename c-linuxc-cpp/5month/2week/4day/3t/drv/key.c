#include <key.h>

void key_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//开启时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	//初始化GPIO
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;//输出模式
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;//无上下拉
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;//PA0
	GPIO_Init(GPIOA, &GPIO_InitStruct);
}


void key_led()
{
	
	int aflag = 0;
	int eflag2 = 0;
	int eflag3 = 0;
	int eflag4 = 0;

	while (1)
	{

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
		if (!GPIO_ReadInputDataBit(GPIOE, GPIO_Pin_4))
		{
			eflag4 = eflag4 == 1 ? 0 : 1;
			if (eflag4 == 1)
			{

				led_onoff(4, 1);
			}
			else
			{
				led_onoff(4, 0);
			}
			delay(500);
		}


	}

}
