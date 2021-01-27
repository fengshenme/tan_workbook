#ifndef _1JOB_H_
#define  _1JOB_H_

#include <iostream>

using namespace std;

struct node
{
    // 数据域
    int num;

    char name[12];

    //指针域
    struct node *next;
};

typedef struct node nn, *nlist;

class NodeList //类声明
{

public:
    nlist initlist(); // 初始化单向循环链表头

    int addNode(nn *new_n, nlist head);
   

    nlist findNode(int num, nlist head);
    

    int delNode(int num, nlist head);
    
};


#endif // 
