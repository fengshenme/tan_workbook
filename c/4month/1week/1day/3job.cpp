using namespace std;
#include <iostream>
#include <list>


struct person
{
    string name;
    int age;
    float height;
};

int initData(list<struct person> &ll)
{
     srand((unsigned int)time(NULL)); // 随机种子
    string na = "abcdefghij";
    int i;
    for ( i = 0; i < 10; i++)
    {
        struct person p1;
        p1.age = rand()%6 + 20 ;// 20到26之间的一个随机数
        p1.height = rand()%230 + 20;// 20到250之间的一个随机数
        p1.name = na[i];

        ll.push_back(p1);
    }

    return 0;
    
}

void printData(list<struct person> &ll)
{
    cout << "姓名" << "年龄" << "身高" << endl;
    for(list<struct person>::iterator it = ll.begin(); it != ll.end(); it++ )
    {
        cout << it->name << ":" << it->age << ":" << it->height << endl;
    }

}

bool ascending(struct person v1,struct person v2)
{
	//升序
	return v1.age < v2.age;
}
bool descending(struct person v1,struct person v2)
{
	//降序
	return v1.height > v2.height;
}

void equal(list<struct person> &ll)
{
    list<struct person>::iterator tmp , pos;
    int age, ct = 0 ;
    pos = ll.end();
    pos--;
    for(list<struct person>::iterator it = ll.begin(); it != ll.end(); it++ )
    {
        // cout << it->name << ":" << it->age << ":" << it->height << endl;
        if (it->age == age)
        {
           ct++; 
           if(it != pos)
           continue;
        }
        if (ct > 0 )
        {
            list<struct person> ta(tmp, it);
            ta.sort(descending);
            
            while(ct >= 0)
            {
                tmp = ll.erase(tmp);
                ct--;
            }
            tmp = it;
            ll.insert(tmp, ta.begin(), ta.end());
            
        }
        tmp = it;
        ct = 0;
        age = it->age;
    }
}

int main(int argc, char const *argv[])
{
    list<struct person> l;
    initData(l);

    printData(l);

    // 按照年龄升序
    l.sort(ascending);
    printData(l);
    // 按照身高降序
    equal(l);
    // l.sort(descending);
    printData(l);

    
    return 0;
}

