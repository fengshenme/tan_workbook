using namespace std;
#include <iostream>
#include <map>

int init_data(multimap<int, string> &m1)
{
    pair<int, string> p[10];
    string na = "abcdefghij";
    int i;
    for ( i = 0; i < 10; i++)
    {
        p[i] = make_pair(i, na[i]);
        m1.insert(p[i]);
    }

    return 0;
}

void printData(multimap<int, string> &m1)
{
    for(multimap<int, string>::iterator mt = m1.begin(); mt != m1.end(); mt++)
    {
        cout << mt->first << ":" << mt->second << endl;
    }

}


int main(int argc, char const *argv[])
{
    multimap<int, string> m1;

    init_data(m1);

    printData(m1);
    return 0;
}
