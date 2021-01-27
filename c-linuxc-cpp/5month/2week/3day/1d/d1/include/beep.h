#ifndef _BEEP_H_
#define _BEEP_H_
#include "sys/stm32f4xx.h"
#include "sys/stm32f4xx_gpio.h"


void beep_init(void);
//state:0,1
void beep_onoff(int state);

#endif 