#include <stm32f4xx.h>

//延时
void delay(unsigned int ms)
{
	int i, j;

	for (i = 0; i < ms; i++)
	{
		for (j = 0; j < 5000; j++)
			;
	}
}

/**
 * @brief 控制4个led灯亮灭
 * 
 * @return int 
 */
int main(void)
{

	
	// //开启GPIOE时钟,GPIOF时钟 RCC_AHB1ENR的第4位置1 ,第5位置1
	RCC->AHB1ENR |= (0x3 << 4); // 11

	// //GPIO初始化
	// //输出模式
	GPIOF->MODER &= ~(0xf << 18); // 1111
	GPIOF->MODER |= (0x5 << 18); // 0101

	GPIOE->MODER &= ~(0xf << 26);
	GPIOE->MODER |= (0x5 << 26);

	//推挽输出
	GPIOF->OTYPER &= ~(0x3 << 9);
	GPIOE->OTYPER &= ~(0x3 << 13);

	//输出速度 50M
	GPIOF->OSPEEDR &= ~(0xf << 18);
	GPIOF->OSPEEDR |= (0xa << 18);

	GPIOE->OSPEEDR &= ~(0xf << 26);
	GPIOE->OSPEEDR |= (0xa << 26);
	//无上下拉
	GPIOF->PUPDR &= ~(0xf << 18);
	GPIOE->PUPDR &= ~(0xf << 26);

	//闪烁
	while (1)
	{

		//延时
		delay(500);
		//亮
		GPIOF->BSRRH |= (0x1 << 9);
		//延时
		delay(500);
		GPIOF->BSRRH |= (0x1 << 10);
		//延时
		delay(500);
		GPIOE->BSRRH |= (0x1 << 13);
		//延时
		delay(500);
		GPIOE->BSRRH |= (0x1 << 14);
		//延时
		delay(500);

		//延时
		delay(500);
		//灭
		GPIOF->BSRRL |= (0x1 << 9);
		//延时
		delay(500);
		GPIOF->BSRRL |= (0x1 << 10);
		//延时
		delay(500);
		GPIOE->BSRRL |= (0x1 << 13);
		//延时
		delay(500);
		GPIOE->BSRRL |= (0x1 << 14);

		//延时
		delay(500);
	}

	return 0;
}
