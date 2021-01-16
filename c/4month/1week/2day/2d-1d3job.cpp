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

//按照年龄进行升序，如果年龄相同按照身高进行降序
bool sortC(struct person v1, struct person v2)
{

    if (v1.age == v2.age)
        //降序
        return v1.height > v2.height;
    else
        //升序
        return v1.age < v2.age;
}

int main(int argc, char const *argv[])
{
    list<struct person> l;
    initData(l);

    printData(l);

    // 按照年龄进行升序，如果年龄相同按照身高进行降序
    l.sort(sortC);
    printData(l);

    
    return 0;
}


template <typename T>
int selectSort(T arr[], int len) //选择排序
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        T tmp = arr[i];
        for (j = i; j > 0; j--)
        {
            if (arr[j - 1] > tmp)
                break;
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }

    return 0;
}