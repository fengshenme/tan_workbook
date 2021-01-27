#include <stm32f4xx.h>
#include <exti.h>
#include <sys.h>
#include <led.h>

#define TIMEOUT 5000 

//中断初始化
void exti_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//1.开始SYSCFG和GPIOA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
	
	//2.初始化GPIO为输入功能
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;//输出模式
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;//无上下拉
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 ;//PA0
	GPIO_Init(GPIOA , &GPIO_InitStruct);
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4;//PA0
	GPIO_Init(GPIOE , &GPIO_InitStruct);
	
	//3.设置GPIO和中断线的映射关系
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource0);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource2);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource3);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource4);
	
	//4.初始化外部中断
	EXTI_InitStruct.EXTI_Line = EXTI_Line0 | EXTI_Line2 | EXTI_Line3 | EXTI_Line4;//外部中断线0
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;//中断模式
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Falling;//下降沿触发
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStruct);
	
	//5.初始化NVIC
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;//中断通道外部中断0
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x2;//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x2;//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);

	NVIC_InitStruct.NVIC_IRQChannel = EXTI2_IRQn;//中断通道外部中断0
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x3;//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x2;//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI3_IRQn;//中断通道外部中断0
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x4;//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x2;//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);

	NVIC_InitStruct.NVIC_IRQChannel = EXTI4_IRQn;//中断通道外部中断0
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x5;//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x2;//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
}


//中断处理函数
void EXTI0_IRQHandler(void)
{
	PFout(9) = 0;
	delay(TIMEOUT);
	PFout(9) = 1;
	
	//清除中断源标志
	EXTI_ClearITPendingBit(EXTI_Line0);
}

//中断处理函数
void EXTI2_IRQHandler(void)
{
	PFout(10) = 0;
	delay(TIMEOUT);
	PFout(10) = 1;
	
	//清除中断源标志
	EXTI_ClearITPendingBit(EXTI_Line2);
}

//中断处理函数
void EXTI3_IRQHandler(void)
{
	PEout(13) = 0;
	delay(TIMEOUT);
	PEout(13) = 1;
	
	//清除中断源标志
	EXTI_ClearITPendingBit(EXTI_Line3);
}

//中断处理函数
void EXTI4_IRQHandler(void)
{
	PEout(14) = 0;
	delay(TIMEOUT);
	PEout(14) = 1;
	
	//清除中断源标志
	EXTI_ClearITPendingBit(EXTI_Line4);
}