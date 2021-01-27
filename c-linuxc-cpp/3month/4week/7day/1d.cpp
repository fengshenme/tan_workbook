#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    system("chcp 65001"); // windos系统 utf8编码显示 使用运行终端gitbash
    cout << "helloworld你好" << endl;
    cout << "nihaoya" << endl;

    vector<int> v;
    int i;
    for ( i = 0; i < 10; i++)
    {
        /* code */
        // v[i] = i;
        v.push_back(i);

    }

    cout << v.size() << endl;
    cout << v.at(3) << endl;
    cout << v[2] << endl;
    
    return 0;
}

