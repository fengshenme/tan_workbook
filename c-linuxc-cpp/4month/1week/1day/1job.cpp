using namespace std;
#include <iostream>
// #include <set>
#include <algorithm>
#include <set>

int init_data(multiset<int> &st1)
{
    int i;

    for (i = 0; i < 10; i++)
    {
        st1.insert(i);
    }
    return 0;
}

void printData(multiset<int> &st)
{
    for (multiset<int>::iterator it = st.begin(); it != st.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << st.size() << " : " << st.max_size() << endl;

    if (!st.empty())
    {
        cout << "not is empty" << endl;
    }
}

int main(int argc, char const *argv[])
{
    multiset<int> st1;

    init_data(st1);
    multiset<int> st2(st1);

    multiset<int> st3 = st1;
    string str1 = "abcdefghij";

    int i;
    multiset<int> st4;
    for (i = 0; i < 10; i++)
    {
        st4.insert(str1[i]);
    }

    st4.swap(st3);

    printData(st1);
    printData(st2);
    printData(st3);
    printData(st4);
    st4.clear();
    printData(st4);
    st1.erase(1);
    st1.erase(st1.begin());
    st1.erase(st1.begin(), ----st1.end());
    printData(st1);


    cout << *st2.find(1) << endl;
    cout << st2.count(5) << endl;

    return 0;
}
