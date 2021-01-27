#include <ultrasonic.h>

#define TRIG PAout(9)
#define ECHO PAin(10)

void UltrasonicInit()
{
    GPIO_InitTypeDef GPIO_InitStruct;

    //开启时钟
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

    //初始化GPIO
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;     //输入模式
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL; //无上下拉

    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10; //PA10
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;  //输出模式
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP; // 推挽
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;      //PA9
    GPIO_Init(GPIOA, &GPIO_InitStruct);

    TRIG = 0;

    TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;

    NVIC_InitTypeDef NVIC_InitStructure;

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    /* 配置中断源 */
    NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    // NVIC_Configuration(); //配置中断函数
    //使能TIM1时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM1, ENABLE);

    TIM_TimeBaseStructure.TIM_Period = 49999;
    TIM_TimeBaseStructure.TIM_Prescaler = 8400 - 1; //设置分频系数为7200
    TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; //设置为向上计数模式

    TIM_TimeBaseInit(TIM1, &TIM_TimeBaseStructure);

    // TIM_ARRPreloadConfig(TIM3,ENABLE);  //使能TIM3重载寄存器
    TIM_ITConfig(TIM1, TIM_IT_Update, ENABLE); //注意这里函数的意思是打开中断，溢出中断
}

//void Conut(void)
//{
//	time = TH0 * 256 + TL0;
//	TH0 = 0;
//	TL0 = 0;
//	S = (time * 1.87) / 100; //算出来是CM
//	if (flag == 1)			 //超出测量
//	{
//		flag = 0;
//		printf("-----\n");
//	}

//	printf("S=%f\n", S);
//}

void StartModule() //
{
    char aa[5];
    run_mess(itoa(55, aa, 10));
    /*发送一个10us的方波*/

    TRIG = 0;
    delay_us(2);
    TRIG = 1; // 启动一次模块 // 设置高电平 1
    delay_us(10);
    TRIG = 0; // 设置低电平 0
    ECHO = 0;
}

void ultrasonic_test()
{
    UltrasonicInit();
    delay_init();
    int i = 0;
    GPIO_ResetBits(GPIOA, GPIO_Pin_9); //trig先拉低电平
    while (1)
    {

        GPIO_SetBits(GPIOA, GPIO_Pin_9); //拉高电平
        delay_us(20);                    //延时20个微秒
        GPIO_ResetBits(GPIOA, GPIO_Pin_9);
        TIM1->CNT = 0; //TIM3的计数器清0

        while (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10) == 0) ; //等待ECHO的高电平

        TIM_Cmd(TIM1, ENABLE); //运行TIM3进行计时
        OLED_Clear();
        OLED_ShowNum(36, 6, i, 3, 16);
        i++;
        run_mess("7989");

        while ((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_10) == 1) && (TIM1->CNT < TIM1->ARR - 10)) ;

        TIM_Cmd(TIM1, DISABLE);

        u16 count = TIM1->CNT;
        run_mess("88---");
        //关闭启动systick

        // OLED_ShowNum(36, 6,  , 3, 16);

        char tmp[8];
        run_mess((u8 *)itoa(count, tmp, 10));

        delay_ms(100); //100MS

        while (1);
    }
}

char *itoa(int num, char *str, int radix)
{
    char index[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //索引表
    unsigned unum;                                         //存放要转换的整数的绝对值,转换的整数可能是负数
    int i = 0, j, k;                                       //i用来指示设置字符串相应位，转换之后i其实就是字符串的长度；转换后顺序是逆序的，有正负的情况，k用来指示调整顺序的开始位置;j用来指示调整顺序时的交换。

    //获取要转换的整数的绝对值
    if (radix == 10 && num < 0) //要转换成十进制数并且是负数
    {
        unum = (unsigned)-num; //将num的绝对值赋给unum
        str[i++] = '-';        //在字符串最前面设置为'-'号，并且索引加1
    }
    else
        unum = (unsigned)num; //若是num为正，直接赋值给unum

    //转换部分，注意转换后是逆序的
    do
    {
        str[i++] = index[unum % (unsigned)radix]; //取unum的最后一位，并设置为str对应位，指示索引加1
        unum /= radix;                            //unum去掉最后一位

    } while (unum); //直至unum为0退出循环

    str[i] = '\0'; //在字符串最后添加'\0'字符，c语言字符串以'\0'结束。

    //将顺序调整过来
    if (str[0] == '-')
        k = 1; //如果是负数，符号不用调整，从符号后面开始调整
    else
        k = 0; //不是负数，全部都要调整

    char temp;                         //临时变量，交换两个值时用到
    for (j = k; j <= (i - 1) / 2; j++) //头尾一一对称交换，i其实就是字符串的长度，索引最大值比长度少1
    {
        temp = str[j];               //头部赋值给临时变量
        str[j] = str[i - 1 + k - j]; //尾部赋值给头部
        str[i - 1 + k - j] = temp;   //将临时变量的值(其实就是之前的头部值)赋给尾部
    }

    return str; //返回转换后的字符串
}