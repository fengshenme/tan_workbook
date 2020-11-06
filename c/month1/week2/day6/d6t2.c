#include <stdio.h>
#include <stdlib.h>

void * heap_request(size_t a);

struct node
{
char itable;
int num[20];
char * togs;
};
int x; 

int main(int argc, char const *argv[])
{
    char *a = heap_request(2);
    a[0] = 'a';
    a[1] = 'b';
    a[2] = 'c';
    printf("%s\n", a);
    return 0;
}

// 申请内存空间
void * heap_request(size_t a)
{

    return malloc(a);
}