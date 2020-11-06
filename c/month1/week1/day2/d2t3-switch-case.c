#include <stdio.h>

int main(int argc, char const *argv[])
{
	int s;
	while(1)
	{
		scanf("%d",&s);
		switch(s)
		{
			case 0:
				printf("bye bye ~ \n");
				return 1;
			case 1:
				printf("tan wei \n");
				break;
			case 2:
				printf("GZ2067 \n");
				break;
			case 3:
				printf("2000 \n");
				break;
			case 4:
				printf("2020 \n");
				break;
			default:
				printf("input error\n");
				break;
		}
	}
	
	return 0;
}