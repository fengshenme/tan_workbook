/**
 * @file d4t4.c
 * @brief 用链表存储若干自然数。比如输入一个整数10后：（双向循环链表）
 * @version 0.1
 * @date 2020-10-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;

    struct node *next;
    struct node *prev;

} link_list, *pl_list;

/**
 * @brief 根据data删除节点
 * 
 * @param data 
 * @param list 
 * @return int 
 */
int del_node(int data, pl_list list);
/**
 * @brief 链表头插入节点n_node
 * 
 * @param n_node 
 * @param list 
 * @return int 
 */
int list_node_add(pl_list n_node, pl_list list);
/**
 * @brief 链表尾插入节点n_node
 * 
 * @param n_node 
 * @param list 
 * @return int 
 */
int list_node_add_tail(pl_list n_node, pl_list list);
/**
 * @brief 初始化链表头部
 * 
 * @return pl_list 
 */
pl_list list_init(void);
/**
 * @brief 创建一个新节点
 * 
 * @param data 
 * @return pl_list 
 */
pl_list new_node(int data);
/**
 * @brief 后序遍历链表所有节点的数据
 * 
 * @param list 
 */
void show_list(pl_list list);
/**
 * @brief 前序遍历链表所有节点的数据
 * 
 * @param list 
 */
void show_list_prev(pl_list list);
void sort_list(pl_list list);

int main(int argc, char const *argv[])
{
    pl_list list = list_init();
    int num;
    while (1)
    {
        printf("Pls input: ");
        scanf("%d", &num);
        while (getchar() != '\n')
            ;
        int i;
        for (i = 1; i <= num; i++)
        {
            list_node_add_tail(new_node(i), list);
        }

        // list_node_add(new_node(num), list);


        show_list(list);
        show_list_prev(list);

        sort_list(list);
        
        show_list(list);
        show_list_prev(list);
        // 
    }

    return 0;
}

void sort_list(pl_list list)
{
    pl_list pos, tmp;
    for (pos = list->next; pos != list; pos = pos->next)
    {
        if ((pos->data)%2==0)
        {
            tmp = pos->prev;
            pos->prev->next = pos->next;
            pos->next->prev = pos->prev;
            list_node_add(pos, list);
            pos = tmp;
        }
        
    }
    for (pos = list->next; pos != list; pos = pos->next)
    {
        if ((pos->data)%2!=0)
        {
            break;
        }
    }
    printf("%d\n", pos->next->data);
    pos->prev->next = list;
    pos->prev = list;
    list->prev->next = list->next;
    list->next = pos;

    if(pos == list)
	{
		printf("Not Found!\n");
		return ;
	}

    return ;    
}

void show_list(pl_list list)
{
    pl_list pos;
    for (pos = list->next; pos != list; pos = pos->next)
    {
        printf("%d ", pos->data);
    }
    printf("\n");
}

void show_list_prev(pl_list list)
{
    pl_list pos;
    for (pos = list->prev; pos != list; pos = pos->prev)
    {
        printf("%d ", pos->data);
    }
    printf("\n");
}

int del_node(int data, pl_list list)
{
    pl_list pos = list->next;

    if (list == pos)
    {
        perror("Empty!!\n");
        return 1;
    }

    while (pos != list)
    {
        if (pos->data == data)
        {
            break;
        }
        pos = pos->next;
    }
    // （如果遍历结束没找到，pos指向list，结束函数）
    if (pos == list)
    {
        printf("Not Found!\n");
        return 2;
    }

    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;
    free(pos);
    return 0;
}

int list_node_add(pl_list n_node, pl_list list)
{
    n_node->prev = list;
    n_node->next = list->next;
    list->next->prev = n_node;
    list->next = n_node;
    return 0;
}
int list_node_add_tail(pl_list n_node, pl_list list)
{
    n_node->next = list;

    n_node->prev = list->prev;

    list->prev->next = n_node;
    list->prev = n_node;
    return 0;
}

pl_list list_init(void)
{
    pl_list head = malloc(sizeof(link_list));
    if (head == NULL)
    {
        printf("malloc fialed\n");
        return NULL;
    }

    head->next = head;
    head->prev = head;
    return head;
}

pl_list new_node(int data)
{
    pl_list node = malloc(sizeof(link_list));
    if (node == NULL)
    {
        printf("malloc fialed\n");
        return NULL;
    }

    node->data = data;
    node->next = node;
    node->prev = node;
    return node;
}
