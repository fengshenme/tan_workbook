#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

int main(int argc, char const *argv[])
{
    
    ofstream ofs("test.txt", ios::out | ios::app);

    if(!ofs.is_open())
    {
        printf("3demo:[%d]open fialed\n", __LINE__);
    }

    ofs << "wangwu" << endl;
    ofs << "w112" << endl;
    ofs << "322asds" << endl;

    ofs.close();

    ifstream ifs("test.txt", ios::in);

    if(!ifs.is_open())
    {
        printf("3demo:[%d]open fialed\n", __LINE__);
    }

    char buf[1024] = {0};
    // while (ifs.getline(buf, 1024))
    // {
    //     cout << buf << endl ;
    //     /* code */
    // }
    while (ifs >> buf)
    {
        cout << buf << endl ;
    }
    
    ifs.close();


    return 0;
}


