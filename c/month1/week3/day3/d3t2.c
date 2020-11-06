#include <stdlib.h>
#include <signal.h>

// # 2.运行程序后，每隔1秒钟，将当前时间写入到 time.txt中
// # 温馨提示：使用 system()、sleep() 函数。
int main(int argc, char const *argv[])
{
    
    while (1)
    {
        system("date >> time.txt");
        sleep(1);
    }
      
    return 0;
}
