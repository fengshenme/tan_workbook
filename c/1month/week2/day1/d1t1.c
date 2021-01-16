#include <stdio.h>

/**
 * 
   *
  ***
 *****
*******
 *****
  ***
   *
*/
int main(void)
{	
	int n;
	scanf("%d", &n); while(getchar()!='\n');

	// 1.打印上半部分
	int i;	//行号
	int j;	
	for(i=1; i<=n; i++)
	{
		// 1.1 打印空格
		for(j=1; j<=n-i; j++)
			printf(" ");

		// 1.2 打印星号*
		for(j=1; j<=2*i-1; j++)
			printf("*");

		printf("\n");
	}

	// 2.打印下半部分
	for(i=1; i<=n-1; i++)
	{
		// 1.1 打印空格
		for( j=1; j<= i; j++)
			printf(" ");

		// 1.2 打印星号*
		for(j=1; j<(n-i)*2; j++)
			printf("*");

		printf("\n");
	}
      

	return 0;
}
