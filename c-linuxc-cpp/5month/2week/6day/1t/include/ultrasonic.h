#ifndef _ULTRASONIC_H_
#define _ULTRASONIC_H_
#include <stm32f4xx.h>
#include <delay.h>
#include <oled.h>

void UltrasonicInit();
void ultrasonic_test();
void StartModule();
/**
 * @brief value: 要转换的整数，string: 转换后的字符串,radix: 转换进制数，如2,8,10,16 进制等。
 * 
 * @param value 
 * @param string 
 * @param radix 
 * @return char* 
 */
char* itoa(int value,char*string,int radix);

#endif