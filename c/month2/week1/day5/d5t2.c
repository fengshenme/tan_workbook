#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{

    int data;

    struct node *next;

} link_list, *pl_list;

int del_list_node(int data, pl_list list);
void list_show(pl_list list);
int list_node_add(pl_list n_node, pl_list list);
pl_list new_node(int data);
pl_list list_init(void);
int list_node_add_tail(pl_list n_node, pl_list list);
int del_three(int num, int n, pl_list list);
int del_t(int num, pl_list list);

int main(int argc, char const *argv[])
{
    int num;
    while (1)
    {
        scanf("%d", &num);
        while (getchar() != '\n')
            ;
        pl_list list = list_init();
        int i;
        for (i = 1; i <= num; i++)
        {
            // list_node_add(new_node(i), list);
            list_node_add_tail(new_node(i), list);
        }
        list_show(list);
        // int n = 1;
        // del_three(num, n, list);
        del_t(num, list);
        list_show(list);
    }

    return 0;
}

int del_t(int num, pl_list list)
{
    pl_list pos;
    pos = list->next;
    int i;
    while (1)
    {
        if (num <= 2)
            break;
        for (i = 0; i < 3; i++)
        {
            pos = pos->next;
            if (pos == list)
                pos = pos->next;
        }

        del_list_node(pos->data, list);
        num--;
    }
    return 0;
}

int del_three(int num, int n, pl_list list)
{
    pl_list pos;
    int arr[num];
    int tmp = 0;
    bzero(arr, num);
    for (pos = list->next; pos != list; pos = pos->next)
    {
        if (n % 3 == 0)
        {
            arr[tmp] = pos->data;
            tmp++;
        }
        n++;
    }
    int i;
    for (i = 0; i < tmp; i++)
    {
        del_list_node(arr[i], list);
    }
    list_show(list);
    if (num - tmp >= 3)
    {
        del_three(num - tmp, n, list);
    }

    return 0;
}

int del_list_node(int data, pl_list list)
{

    // A. 判断是否为空链
    if (list->next == list)
    {
        printf("Empty!\n");
        return 1;
    }
    pl_list pos = list->next;
    pl_list pre = list;
    for (; pos != list; pre = pos, pos = pos->next)
    {
        if (pos->data == data)
            break;
    }
    // （如果遍历结束没找到，pos指向head，结束函数）
    if (pos == list)
    {
        printf("Not Found!\n");
        return 2;
    }
    pre->next = pos->next;

    free(pos);
    return 0;
}

pl_list list_init(void)
{
    pl_list head = malloc(sizeof(link_list));
    if (head == NULL)
    {
        perror("new_node malloc fialed!\n");
        return NULL;
    }

    head->next = head;
    return head;
}

void list_show(pl_list list)
{
    pl_list pos;
    for (pos = list->next; pos != list; pos = pos->next)
    {
        printf("%d ", pos->data);
    }
    printf("\n");
}

int list_node_add(pl_list n_node, pl_list list)
{
    n_node->next = list->next;
    list->next = n_node;

    return 0;
}

int list_node_add_tail(pl_list n_node, pl_list list)
{
    pl_list pos;
    for (pos = list; pos->next != list; pos = pos->next)
        ;
    n_node->next = pos->next;
    pos->next = n_node;
    return 0;
}

pl_list new_node(int data)
{
    pl_list n_node = malloc(sizeof(link_list));
    if (n_node == NULL)
    {
        perror("new_node malloc fialed!\n");
        return NULL;
    }

    n_node->data = data;
    n_node->next = n_node;
    return n_node;
}
