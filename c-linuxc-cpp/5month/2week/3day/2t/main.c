#include <stm32f4xx.h>
#include <led.h>


int main(void)
{

	//开启GPIOF时钟 RCC_AHB1ENR的第5位置1 开启GPIOE时钟 RCC_AHB1ENR的第4位置1
	RCC->AHB1ENR |= (0x3 << 4);

	//GPIO初始化
	//输出模式
	GPIOF->MODER &= ~(0xf << 18); // 1111
	GPIOF->MODER |= (0x5 << 18);  // 0101

	GPIOF->MODER &= ~(0x3 << 16);
	GPIOF->MODER |= (0x1 << 16);

	GPIOE->MODER &= ~(0xf << 26);
	GPIOE->MODER |= (0x5 << 26);

	//推挽输出 pf两个灯以及蜂鸣器
	GPIOF->OTYPER &= ~(0x7 << 8); // 111

	// pe2个led灯
	GPIOE->OTYPER &= ~(0x3 << 13);

	//输出速度 50M led
	GPIOF->OSPEEDR &= ~(0xf << 18); // 1111
	GPIOF->OSPEEDR |= (0xa << 18);	// 1010

	GPIOE->OSPEEDR &= ~(0xf << 26);
	GPIOE->OSPEEDR |= (0xa << 26);
	// 蜂鸣器
	GPIOF->OSPEEDR &= ~(0x3 << 16); // 11
	GPIOF->OSPEEDR |= (0x0 << 16);	// 1

	//无上下拉
	GPIOF->PUPDR &= ~(0xf << 18);

	GPIOE->PUPDR &= ~(0xf << 26); // 1111
	// 蜂鸣器
	GPIOF->PUPDR &= ~(0x3 << 16);

	GPIOF->BSRRL |= (0x1 << 8);

	//延时
	delay(500);

	GPIOF->BSRRH |= (0x1 << 8);

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
