#include <stm32f4xx.h>
#include <timer.h>
#include <sys.h>

void timer2_init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//1.使能定时器时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10, ENABLE);
	
	//2.初始化定时器2
	//84MHz / 8400 = 10KHz
	TIM_TimeBaseInitStruct.TIM_Prescaler = 8400-1;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Down;//向下计数
	//10KHz X 10000 = 1s
	TIM_TimeBaseInitStruct.TIM_Period = 10000;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
	
	//10KHz X 5000 = 500ms
	TIM_TimeBaseInitStruct.TIM_Period = 5000;
	TIM_TimeBaseInit(TIM10, &TIM_TimeBaseInitStruct);

	//3.初始化NVIC
	NVIC_InitStruct.NVIC_IRQChannel = TIM2_IRQn;//TIM2
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0x2;//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 0x2;//响应优先级
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStruct);
	
		NVIC_InitStruct.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;//TIM10
		NVIC_Init(&NVIC_InitStruct);
	
	//4.使能定时器2中断
	TIM_ITConfig(TIM2, TIM_IT_Update,ENABLE);
	
	TIM_ITConfig(TIM10, TIM_IT_Update,ENABLE);
	
	//6.使能定时器中断
	TIM_Cmd(TIM2,ENABLE);
	
	TIM_Cmd(TIM10,ENABLE);
}

//5.定时器中断函数
void TIM2_IRQHandler(void)
{
	//处理更新中断
	if(TIM_GetITStatus(TIM2,TIM_IT_Update)==SET){
		PFout(10) ^= 1;
		
		//清除中断标志
		TIM_ClearITPendingBit(TIM2,TIM_IT_Update);
	}
}

//5.定时器中断函数
void TIM1_UP_TIM10_IRQHandler(void)
{

		//处理更新中断
	if(TIM_GetITStatus(TIM10,TIM_IT_Update)==SET){
		PEout(14) ^= 1;
		
		//清除中断标志
		TIM_ClearITPendingBit(TIM10,TIM_IT_Update);
	}
	
}
