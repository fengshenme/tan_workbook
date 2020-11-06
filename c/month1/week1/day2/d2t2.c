#include <stdio.h>

int main(int argc, char const *argv[])
{
	
	int i;
	for(i = 0; i < 10; ++i)
	{
		int s;
		printf("pls input cmd :\n");
		scanf("%d",&s);while(getchar() != '\n');
		printf("%d \n", s);
		if (s==0)
		{
			printf("bye bye ~ \n");
			return 1;
		}
		else if(s == 1)
		{
			printf("tan wei \n");
		}
		else if (s == 2)
		{
			printf("GZ2067 \n");
		}
		else if (s == 3)
		{
			printf("2001 \n");
		}
		else
		{
			printf("input error\n");
		}		
	}
	return 0;
}