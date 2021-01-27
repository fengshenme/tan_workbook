#include <delay.h>


static u8 fac_us = 0;  //us延时倍乘数
static u16 fac_ms = 0; //ms延时倍乘数


/**
 * @brief 初始化延迟函数 
 * 
 * SYSTICK:的时钟固定为HCLK时钟的1/8
 * SYSCLK:系统时钟
 * 
 */
void delay_init()
{

	//选择原始时钟为HCLK/8 = 21MHz
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);

	fac_us = SystemCoreClock / 8000000; //为系统时钟的1/8

	fac_ms = (u16)fac_us * 1000; // 代表每个ms需要的systick时钟数
}

/**
 * @brief 延时nus
 * 
 * @param nus nus为要延时的us数.
 */
void delay_us(u32 nus)
{
	u32 temp;
	SysTick->LOAD = nus * fac_us;			  //时间加载
	SysTick->VAL = 0x00;					  //清空计数器
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; //开始倒数
	do
	{
		temp = SysTick->CTRL;
	} while (temp & 0x01 && !(temp & (1 << 16))); //等待时间到达
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;	  //关闭计数器
	SysTick->VAL = 0X00;						  //清空计数器
}

/**
 * @brief 延时nms 注意nms的范围
 * SysTick->LOAD为24位寄存器,所以,最大延时为:
 * nms<=0xffffff*8*1000/SYSCLK SYSCLK单位为Hz,nms单位为ms
 * 对72M条件下,nms<=1864
 * 
 * @param nms nms为要延时的ms数.
 */
void delay_ms(u32 nms)
{
	u32 temp;
	SysTick->LOAD = (u32)nms * fac_ms;		  //时间加载(SysTick->LOAD为24bit)
	SysTick->VAL = 0x00;					  //清空计数器
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; //开始倒数
	do
	{
		temp = SysTick->CTRL;
	} while (temp & 0x01 && !(temp & (1 << 16))); //等待时间到达
	SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;	  //关闭计数器
	SysTick->VAL = 0X00;						  //清空计数器
}
