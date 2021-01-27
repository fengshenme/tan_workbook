#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{

    // 在代码中设置 终端chcp 65001 中文正常显示
    cout << "设置utf8显示成功" << endl;
    system("chcp 65001"); // utf8编码
    cout << "年后" << endl;

    return 0;
}
