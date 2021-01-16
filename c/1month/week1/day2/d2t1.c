#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	float o;
	char t;
	scanf("%d",&i);while(getchar() != '\n');
	
	// scanf("%s",&t);
	// scanf("%f",&o);
	// printf("9 %f\n",o);
	// printf("12 %d \n", t);

	int j;
	for (j = 0; j < i; j++)
	{
		if(j%2 ==1 )
		{
			printf(" %d ",j);
		}
	}
	printf("\n");

	return 0;
}