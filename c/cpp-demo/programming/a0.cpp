#include <stdio.h>

int main() {
    int i = 0;
    while(i<1000000){
        if(!(i%10000)){
            printf("%d\n",i);
        }
        i++;
    }
    return 0;
}