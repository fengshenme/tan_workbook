#include <led.h>

//延时
void delay(unsigned int ms)
{
	int i, j;

	for (i = 0; i < ms; i++)
	{
		for (j = 0; j < 5000; j++)
			;
	}
}
