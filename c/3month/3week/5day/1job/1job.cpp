#include "1job.h"

nlist NodeList::initlist() // 初始化单向循环链表头
{
    nlist head = new nn;

    head->next = head;

    return head;
}

int NodeList::addNode(nn *new_n, nlist head)
{
    new_n->next = head->next;
    head->next = new_n;
    return 0;
}

nlist NodeList::findNode(int num, nlist head)
{

    nlist tmp;
    for (tmp = head->next; tmp->next != head; tmp = tmp->next)
    {

        if (tmp->num == num)
        {
            break;
        }
    }

    return tmp;
}

int NodeList::delNode(int num, nlist head)
{
    nlist tmp, prev;
    for (tmp = head->next; tmp->next != head; tmp = tmp->next)
    {

        if (tmp->num == num)
        {
            break;
        }
        prev = tmp;
    }

    prev->next = tmp->next;

    delete tmp;

    return 0;
}

int main(int argc, char const *argv[])
{
    NodeList c;

    nlist hl = c.initlist();
    int i;
    for (i = 0; i < 10; i++)
    {
        nn *nod = new nn;
        nod->num = i;
        sprintf(nod->name, "%d abcd", i);

        c.addNode(nod, hl);
    }

    nlist tmp;
    for (tmp = hl->next; tmp->next != hl; tmp = tmp->next)
    {

        printf("%d---%s\n", tmp->num, tmp->name);
    }

    for (i = 0; i < 10; i++)
    {

        c.delNode(i, hl);
    }

    delete hl;
    return 0;
}
