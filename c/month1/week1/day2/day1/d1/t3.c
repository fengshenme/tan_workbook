#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	for ( i = 30; i <= 65; i++)
	{
		/* code1l iI I L l */
		printf("%d\n", i );
	}
	int j = 30;
	while(j<=65)
	{
		printf("%d\n",j );
		j++;	
	}
	int year = (65-30);
	int month  = year*12;
	int day = year*365;
	int hour = day*24;
	int minute = hour* 60;
	int second = minute*60;
	printf("%d 总月数\n", month);
	printf("%d 总天数\n", day);
	printf("%d 总小时数\n", hour);
	printf("%d 总分钟数\n", minute);
	printf("%d 总秒数\n", second);
	int h ;
	for (h = 0; h < 5; h++)
	{
		/* code */
		int g = h;
		while(g>=0)
		{
			printf("%s","*");
			g--;
		}
		printf("\n");
	}

	return 0;
}
