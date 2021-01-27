#include <iostream>
// #include <string>

using namespace std;

// 2、输入一个字符串，把其中字符按照逆序输出，如ABCD,输出为DCBA，要求使用string存储字符串

int main(int argc, char *argv[])
{
    string str1 = "abcdef";
    int len = str1.size();
    
    int i;
    char tmp;
    for ( i = 0; i < len/2; i++)
    {
        tmp = str1[len-1-i];
        str1[len-1-i] = str1[i];
        str1[i] = tmp;
    }
    cout << str1 << endl;

}
