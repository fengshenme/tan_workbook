/*

7、假设有以下说明和定义：
 typedef union
{
    long i;
    int k[5];
    char c;
} fruit;
struct creature
{
    short cat;
    fruit apple;
    double dog;
};
fruit berry;
则语句 printf("%d", sizeof(struct creature) + sizeof(berry));
的执行结果是？ 2-8 8-8 8-8 4-8 8-8 40
20-24 24
结果64
*/
#include <stdio.h>

 typedef union
{
    long i;
    int k[5];
    char c;
} fruit;
struct creature
{
    short cat;
    fruit apple;
    double dog;
};
fruit berry;

int main(int argc, char const *argv[])
{

    printf("%ld\n", sizeof(struct creature) + sizeof(berry));
    printf("%ld\n", sizeof(struct creature) );
    printf("%ld\n",  sizeof(berry));
    return 0;

}
