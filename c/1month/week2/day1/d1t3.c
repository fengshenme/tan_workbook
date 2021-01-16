#include <stdio.h>

int main(int argc, char const *argv[])
{
    int pig_weight[5] = {200,100,400,900,300};

    int max = 0;

    for (size_t i = 0; i < 5; i++)
    {
        if (max < pig_weight[i])
            max = pig_weight[i];
    }
    
    printf("%d", max);

    return 0;
}
