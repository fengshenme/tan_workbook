#ifndef _LED_H_
#define _LED_H_
#include "sys/stm32f4xx.h"
#include "sys/stm32f4xx_gpio.h"

void delay(unsigned int ms);

void depa();

void display();

void led_init(void);
//num:1,2,3,4  state:0,1
void led_onoff(int led_num,int state);

#endif 
