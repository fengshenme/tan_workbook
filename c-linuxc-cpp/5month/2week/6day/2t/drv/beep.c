#include <beep.h>

/**
 * @brief 蜂鸣器初始化
 * 
 */
void beep_init(void)
{
	//开启GPIOF E时钟 RCC_AHB1ENR的第4~5位置1
	RCC->AHB1ENR |= (0x1<<5);

	//GPIO初始化
	//输出模式
	GPIOF->MODER &= ~(0x3<<16);//
	GPIOF->MODER |= (0x1<<16);// 01

	//推挽输出
	GPIOF->OTYPER &= ~(0x1<<8);
	
	//输出速度 50M
	GPIOF->OSPEEDR &= ~(0x3<<16);
	GPIOF->OSPEEDR |= (0x2<<16);//1010

	//无上下拉
	GPIOF->PUPDR &= ~(0x3<<16);
	
	//默认不响
	GPIOF->BSRRH |= (0x1<<8);
}

/**
 * @brief 蜂鸣器测试开关
 * 
 * @param state 
 */
void beep_onoff(int state)
{
//	if(state)
//		GPIOF->BSRRL |= (0x1<<8);
//	else
//		GPIOF->BSRRH |= (0x1<<8);
	
	if(state)
		PFout(8) = 1;//输出高
	else
		PFout(8) = 0;
}
