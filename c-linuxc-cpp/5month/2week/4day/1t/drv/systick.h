#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include <stm32f4xx.h>

void systick_init(void);
void delay_ms(u32 nms);

#endif
