#include <stdio.h>

#define MIN(a, b) ({\
    typeof(a) _a=a;\
    typeof(b) _b=b;\
    ((_a)>(_b)?(_b):(_a));\
     })
// ?# 写一个带参数的宏 MIN(x, y)，这个宏输入两个参数并返回较小的一个
int main(int argc, char const *argv[])
{
    printf("%d\n", MIN(8, 10));
    return 0;
}
