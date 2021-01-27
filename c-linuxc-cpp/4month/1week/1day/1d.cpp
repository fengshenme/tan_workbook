#include <iostream>

using namespace std;
#include <vector>
#include <deque>
#include <algorithm>
#include <string>

struct player
{
    string num;
    deque<float> de;
};

int main(int argc, char const *argv[])
{
    srand((unsigned int)time(NULL)); // 随机种子

    system("chcp 65001"); // windos系统 utf8编码显示 使用运行终端gitbash
    vector<struct player> ve;
    string name = "ABCDE";
    string nam = "选手";
    struct player pl[5];
    int i, j;
    for ( i = 0; i < 5; i++)
    {
        pl[i].num = nam + name[i];
        for ( j = 0; j < 10; j++)
        {
            // int tmp = 60 + (int)((float)40 * rand() / (RAND_MAX + 1.0)); // 60到100之间的一个随机数
            int tmp = rand()%41 + 60;// 60到100之间的一个随机数
            cout << tmp << " ";
            pl[i].de.push_back((float)tmp) ;
        }
        
        cout << endl;
        ve.push_back(pl[i]);
    }
    float met;
    int count;
    cout << "选手 :\t评分" << endl;
    for ( i = 0; i < 5; i++)
    {
        sort(ve.at(i).de.begin(), ve.at(i).de.end() );
        ve.at(i).de.pop_front(); //删除最低分
        ve.at(i).de.pop_back(); // 删除最高分
        met = 0.0;
        count = ve.at(i).de.size();
        for ( j = 0; j < count; j++)
        {
            met += ve.at(i).de.at(j);
        }
        //  cout << count << endl;
        cout << ve.at(i).num << ":\t" << met/count << endl;
    }
    
    
    return 0;
}
