#include <stm32f4xx.h>
#include <pwm.h>
#include <systick.h>

void pwm_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	TIM_OCInitTypeDef TIM_OCInitStruct;

	//1.开启时钟
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

	//2.初始化GPIOE14为复用功能
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF;	//输出模式
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP; //推挽
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL; //无上下拉
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14;		  //PF9
	GPIO_Init(GPIOE, &GPIO_InitStruct);

	//3.将TIM1的复用功能映射到Pe14
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_TIM1);

	//4.初始化TIM1
	TIM_TimeBaseInitStruct.TIM_Prescaler = 84 - 1;				   //1MHz
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Down; //向下计数
	//1MHz X 1000 = 1ms
	TIM_TimeBaseInitStruct.TIM_Period = 1000;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM1, &TIM_TimeBaseInitStruct);

	//5.初始化PWM
	TIM_OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;		  //PWM1模式
	TIM_OCInitStruct.TIM_Pulse = 50;					  //比较计数值
	TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_Low; //低电平有效 
	// TIM_OCInitStruct.TIM_OCPolarity = TIM_OCPolarity_High; //高电平有效 
	TIM_OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC4Init(TIM1, &TIM_OCInitStruct);

	//6.开始预装载和自动重装载
	TIM_OC4PreloadConfig(TIM1, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM1, ENABLE);
	
	//7.启动定时器
	TIM_Cmd(TIM1, ENABLE);
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
}

/**
 * @brief 测试pwm 使用PWM驱动LED4作为呼吸灯
 * 
 */
void pwm_test()
{
	
	pwm_init();
	int count = 0;

	while (1)
	{

		//比较值1000->0
		//0->1000
		//每次修改要延时
		while (count < 1000)
		{
			TIM_SetCompare4(TIM1, count++);

			// TIM_CtrlPWMOutputs

			u_delay_ms(1);
		}
		u_delay_ms(100);
		while (count > 0)
		{
			TIM_SetCompare4(TIM1, count--);
			u_delay_ms(1);
		}

		u_delay_ms(100);
	}
}
