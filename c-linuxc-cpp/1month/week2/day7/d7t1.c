#include <stdio.h>

struct animals1
{
    char dog;
    unsigned long cat;
    unsigned short pig;
    char fox;
};
struct animals2
{
    
    unsigned long cat;
    unsigned short pig;
    char dog;
    char fox;
};
union un1
    {
        int a;
        int b;
        double e;
        char c;
        
    } acc, *xa;

struct animals3
{
     union un1 u23;
    short pig;
    char fox;
    double dog;
    
     
}antt;

int main(int argc, char const *argv[])
{
    
    printf("%lu\n",sizeof(struct animals1));
    printf("%lu\n",sizeof(struct animals2));
    printf("%lu\n",sizeof(struct animals3));
    printf("------------\n");
    printf("%lu\n",sizeof(long));
    printf("%lu\n",sizeof(short));
    printf("%lu\n",sizeof(char));
    struct animals3 ansd = {12,12,'a',12.3};
    printf("%d\n",ansd.u23);

    return 0;
}
