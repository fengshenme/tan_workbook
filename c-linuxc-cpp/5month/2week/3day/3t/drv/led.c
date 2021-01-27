#include <led.h>

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


void depa()
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
}

void display()
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


/**
 * @brief 使用库函数进行 led的初始化
 * 
 */
void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	//开启时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	//初始化GPIO
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;//输出模式
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;//推挽
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;//无上下拉
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9|GPIO_Pin_10;//PF9 PF10
	GPIO_Init(GPIOF, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13|GPIO_Pin_14;//PE13 PE14
	GPIO_Init(GPIOE, &GPIO_InitStruct);
}


/**
 * @brief 控制led灯亮灭
 * 
 * @param led_num 灯的编号
 * @param state 1是亮 0 是灭
 */
void led_onoff(int led_num,int state)
{
	switch(led_num){
		case 1:
			if(state)
				GPIO_SetBits(GPIOF,GPIO_Pin_9);
			else
				GPIO_ResetBits(GPIOF,GPIO_Pin_9);
			break;
		case 2:
			if(state)
				GPIO_SetBits(GPIOF,GPIO_Pin_10);
			else
				GPIO_ResetBits(GPIOF,GPIO_Pin_10);
			break;
		case 3:
			if(state)
				GPIO_SetBits(GPIOE,GPIO_Pin_13);
			else
				GPIO_ResetBits(GPIOE,GPIO_Pin_13);
			break;
		case 4:
			if(state)
				GPIO_SetBits(GPIOE,GPIO_Pin_14);
			else
				GPIO_ResetBits(GPIOE,GPIO_Pin_14);
			break;
	}
}
