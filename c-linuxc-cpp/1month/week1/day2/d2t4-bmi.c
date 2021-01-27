#include <stdio.h>

int main(int argc, char const *argv[])
{
	float weight;
	float height;
	float bmi;
	printf("体重(kg):");
	scanf("%f",&weight);
	printf("身高(m):");
	scanf("%f",&height);

	bmi = weight / (height*height);
	printf("BMI指数: %.3f \n",bmi);
	if (bmi <= 18.4)
	{
		printf("体重偏轻 \n");
	}
	else if(bmi>=18.5 && bmi <=23.9)
	{
		printf("体重正常 \n");
	}
	else if(bmi>=24.0 && bmi <=27.9)
	{
		printf("体重过重 \n");
	}
	else if(bmi >= 28.0)
	{
		printf("体重肥胖 \n");
	}

	return 0;
}