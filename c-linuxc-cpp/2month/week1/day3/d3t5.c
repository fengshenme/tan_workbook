
/**
 * @file d3t5.c
 * @author 1015956962@163.com
 * *@brief 单向循环链表 已实现添加,删除,链表初始化,节点创建
 * @version 1.0
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
} link_list;

/**
 * @brief 创建新节点
 * @param data 整型数据
 * @return 返回节点指针
*/
link_list *new_node(int data);
/**
 * @brief 初始化空链头
 * @return 返回空链头指针
*/
link_list *list_init(void);
/**
 * *@brief 打印链表
 * @param list 单向循环链表的指针
*/
void list_show(link_list *pos);

/**
 * @brief 链表头添加新节点
 * @param n_node 要添加的新节点的指针
 * @param list 单向循环链表的指针
 * @return 成功返回0
*/
int list_add(link_list *n_node, link_list *list);
/**
 * @brief 链表尾添加新节点
 * @param n_node 要添加的新节点的指针
 * @param list 单向循环链表的指针
 * @return  成功则返回0, 失败则返回1
*/
int list_tail_add(link_list *n_node, link_list *list);

/**
 * @brief 链表尾添加新节点
 * @param n_node 要添加的新节点的指针
 * @param list 单向循环链表的指针
 * @return  成功则返回0, 失败则返回1
*/
int del_node(int data, link_list *list);

int main(int argc, char const *argv[])
{

    int len = 9;
    int arr[] = {8, 2, 9, 4, 7, 6, 5, 3, 1};
    link_list *list = list_init();
    int i;
    for (i = 0; i < len; i++)
    {
        list_add(new_node(arr[i]), list);
    }
    list_show(list);
    link_list *lista = list_init();
    for (i = 0; i < len; i++)
    {
        list_tail_add(new_node(arr[i]), lista);
    }
    list_show(lista);
    del_node(2, lista);
    list_show(lista);

    return 0;
}

/**
 * @brief 删除节点
 * @param data 要删除的整型数
 * @param list 单向循环链表的指针
 * @return 返回0执行成功, 返回1执行失败
*/
int del_node(int data, link_list *list)
{
    if (list->next == list)
    {
        printf("Empty\n");
        return 1;
    }
    link_list *pos=list, *pre;
    for(; pos->next !=list; pre = pos, pos=pos->next)
    {
        if (pos->data == data)
            break;
    }

    pre->next = pos->next;
    free(pos);
    return 0;

}

/**
 * @brief 链表尾添加新节点
 * @param n_node 要添加的新节点的指针
 * @param list 单向循环链表的指针
 * @return  成功则返回0, 失败则返回1
*/
int list_tail_add(link_list *n_node, link_list *list)
{
    link_list *pos;
    for (pos = list; pos->next != list; pos = pos->next);

    n_node->next = pos->next;
    pos->next = n_node;

    return 0;
}

/**
 * @brief 链表头添加新节点
 * @param n_node 要添加的新节点的指针
 * @param list 单向循环链表的指针
 * @return 成功返回0
*/
int list_add(link_list *n_node, link_list *list)
{

    n_node->next = list->next;
    list->next = n_node;
    return 0;
}

/**
 * *@brief 打印链表
 * @param list 单向循环链表的指针
*/
void list_show(link_list *list)
{
    link_list *pos;
    for (pos = list->next; pos != list; pos = pos->next)
    {
        printf("%d ", pos->data);
    }
    printf("\n");
}

/**
 * @brief 创建新节点
 * @param data 整型数据
 * @return 返回节点指针
*/
link_list *new_node(int data)
{
    link_list *n_node = malloc(sizeof(link_list));
    if (n_node == NULL)
    {
        printf("malloc fialed!\n");
        return NULL;
    }
    n_node->data = data;
    n_node->next = n_node;

    return n_node;
}

/**
 * @brief 初始化空链头
 * @return 返回空链头指针
*/
link_list *list_init(void)
{
    link_list *head = malloc(sizeof(link_list));
    if (head == NULL)
    {
        printf("malloc fialed!\n");
        return NULL;
    }
    head->next = head;

    return head;
}
