
/**
 * @file d4t1.c
 * @author tan wei feng (1015956962@163.com)
 * @brief 单向循环链表 已实现添加,删除,链表初始化,节点创建
 * @version 0.1
 * @date 2020-10-22
 * 
 * todo 预添加功能
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
    int data;

    struct node *next;

} link_list, *link_pl;

/**
 * @brief 创建新节点
 * @param data 整型数据
 * @return 返回节点指针
*/
link_pl new_node(int data);
/**
 * @brief 初始化空链头
 * @return 返回空链头指针
*/
link_pl list_init(void);
/**
 * *@brief 打印链表
 * @param list 单向循环链表的指针
*/
void list_show(link_pl pos);

/**
 * @brief 链表头添加新节点
 * @param n_node 要添加的新节点的指针
 * @param list 单向循环链表的指针
 * @return 成功返回0
*/
int list_add(link_pl n_node, link_pl list);
/**
 * @brief 链表尾添加新节点
 * @param n_node 要添加的新节点的指针
 * @param list 单向循环链表的指针
 * @return  成功则返回0, 失败则返回1
*/
int list_tail_add(link_pl n_node, link_pl list);

/**
 * @brief 链表尾添加新节点
 * @param n_node 要添加的新节点的指针
 * @param list 单向循环链表的指针
 * @return  成功则返回0, 失败则返回1
*/
int del_node(int data, link_pl list);

/**
 * @brief while循环打印链表
 * 
 * @param list 
 */
void while_show(link_pl list);

int main(int argc, char const *argv[])
{

    link_pl list = list_init();
    while (1)
    {
        int num;
        printf("Pls Input: ");
        scanf("%d", &num);
        while (getchar() != '\n')
            ;

        if (num > 0)
        {
            // 添加数据
            list_add(new_node(num), list);
            //  list_tail_add(new_node(num), list);
        }
        else if (num < 0)
        { // 删除数据

            del_node(-num, list);
        }
        else
        { // 打印链表数据
            // list_show(list);
            // while_show(list);
            link_pl pos = list->next;
            while (1)
            {

                printf("%d \n", list->data);
                pos = pos->next;
                if (pos == list)
                {
                    pos = pos->next;
                }
                sleep(1);
            }
        }
    }

    return 0;
}

void while_show(link_pl list)
{
    link_pl pos = list->next;
    while (pos != list)
    {

        printf("%d ", pos->data);
        pos = pos->next;
    }
    printf("\n");
}

/**
 * @brief 删除节点
 * @param data 要删除的整型数
 * @param list 单向循环链表的指针
 * @return 返回0执行成功, 返回1执行失败
*/
int del_node(int data, link_pl list)
{
    if (list->next == list)
    {
        printf("Empty\n");
        return 1;
    }
    link_pl pos = list, pre;
    for (; pos->next != list; pre = pos, pos = pos->next)
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
int list_tail_add(link_pl n_node, link_pl list)
{
    link_pl pos;
    for (pos = list; pos->next != list; pos = pos->next)
        ;

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
int list_add(link_pl n_node, link_pl list)
{

    n_node->next = list->next;
    list->next = n_node;
    return 0;
}

/**
 * *@brief 打印链表
 * @param list 单向循环链表的指针
*/
void list_show(link_pl list)
{
    link_pl pos;
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
link_pl new_node(int data)
{
    link_pl n_node = malloc(sizeof(link_list));
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
link_pl list_init(void)
{
    link_pl head = malloc(sizeof(link_list));
    if (head == NULL)
    {
        printf("malloc fialed!\n");
        return NULL;
    }
    head->next = head;

    return head;
}
