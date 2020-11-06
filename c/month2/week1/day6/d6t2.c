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

} link_node, *pl_list;

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
/**
 * @brief 排序 即奇数升序偶数降序
 * 
 * @param list 
 */
void sort_list(pl_list list);
/**
 * @brief 查找节点
 * 
 * @param data 
 * @param list 
 * @return pl_list 
 */
pl_list find_node(int data, pl_list list);

/**
 * @brief 将一个节点插入目标节点后
 * 
 * @param des_node 
 * @param n_node 
 * @return int 
 */
int insert_node_next(pl_list des_node, link_node *n_node);
/**
 * @brief 将一个节点插入目标节点前
 * 
 * @param des_node 
 * @param n_node 
 * @return int 
 */
int insert_node_prev(pl_list des_node, link_node *n_node);

/**
 * @brief 从链表中提取节点
 * 
 * @param n_node 
 * @return link_node* 
 */
link_node *extract_node(link_node *n_node);

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
    for (pos = list->prev; pos != list; pos = pos->prev)
    {
        if ((pos->data) % 2 == 0)
        {
            tmp = pos->prev;
            insert_node_prev(list, extract_node(pos));
            pos = tmp;
        }
    }

}

pl_list find_node(int data, pl_list list)
{
    pl_list pos = list->next;

    if (list == pos)
    {
        perror("Empty!!\n");
        return NULL;
    }

    while (pos != list)
    {
        if (pos->data == data)
            break;
        pos = pos->next;
    }
    // （如果遍历结束没找到，pos指向list，结束函数）
    if (pos == list)
    {
        perror("Not Found!\n");
        return NULL;
    }
    return pos;
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
    pl_list pos = find_node(data, list);
    pos = extract_node(pos);
    free(pos);
    return 0;
}

link_node *extract_node(link_node *n_node)
{
    n_node->prev->next = n_node->next;
    n_node->next->prev = n_node->prev;
    n_node->next = n_node;
    n_node->prev = n_node;
    return n_node;
}

int insert_node_next(pl_list des_node, link_node *n_node)
{
    n_node->prev = des_node;
    n_node->next = des_node->next;
    des_node->next->prev = n_node;
    des_node->next = n_node;
    return 0;
}

int insert_node_prev(pl_list des_node, link_node *n_node)
{
    n_node->next = des_node;
    n_node->prev = des_node->prev;
    des_node->prev->next = n_node;
    des_node->prev = n_node;
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
    pl_list head = malloc(sizeof(link_node));
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
    pl_list node = malloc(sizeof(link_node));
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
