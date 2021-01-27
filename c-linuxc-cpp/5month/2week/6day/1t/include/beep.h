#ifndef _BEEP_H_
#define _BEEP_H_
#include <stm32f4xx.h>
#include <sys.h>


void beep_init(void);
//state:0,1
void beep_onoff(int state);

#endif
