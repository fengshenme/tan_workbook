#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	printf("请输入年龄:");
	scanf("%d",&i); 
	while(getchar()!='\n');
	int year = (65-i);
	int j = i;
	for ( ; i <= 65; i++)
	{
		printf("%d ", i );
	}
	printf("\n");
	while(j<=65)
	{
		printf("%d ",j );
		j++;	
	}
	printf("\n");
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
	int h ,k;
	printf("请确定层数：" );
	scanf("%d",&h); 
	while(getchar()!='\n');

	for (k=0; k < h; k++)
	{
		/* code */
		int g = k;
		while(g>=0)
		{
			printf("%s","*");
			g--;
		}
		printf("\n");
	}

	return 0;
}
