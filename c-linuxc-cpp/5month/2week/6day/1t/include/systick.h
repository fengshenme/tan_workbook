#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include <stm32f4xx.h>

void u_systick_init(void);
void u_delay_ms(u32 nms);
void u_delay_us(u32 us);
void u_delay_s(u32 s);

#endif
