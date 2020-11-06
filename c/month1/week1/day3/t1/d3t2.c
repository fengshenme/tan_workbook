#include <stdio.h>

int main(int argc, char const *argv[])
{
    char h[12] = "hello,123";
    printf("%s \n",h);
    
    char c[6] = "Jack";
    int j;
    for(j=0;j<5;j++)
    {
       h[j+6]=c[j];
    }
    
    printf("%s \n",h);
    return 0;
}
