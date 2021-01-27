/**
 * @file d3t4.c
 * @author tan wei feng (1015956962@163.com)
 * @brief 
 * @version 0.1
 * @date 2020-10-22
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;

    struct node *next;
};


/**
 * @brief 初始化空链表
 * 
 * @return struct node* 
 */
struct node * list_init(void);
/**
 * @brief 创建新节点
 * 
 * @param data 
 * @return struct node* 
 */
struct node * new_node(int data);
//打印链表
void show_list(struct node *list);
//添加节点到链头
int list_node_add(struct node *n_node, struct node * list);
//添加节点到链尾
int list_node_tail_add(struct node *n_node, struct node * list);
//删除节点
int del_node(int data, struct node * list);

/**
 * @brief 建立一个包含若干整数的单向链表，然后通过某些算法，将其中的数据翻转
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char const *argv[])
{
    struct node * hl = list_init();

    int len = 9;
    int arr[] = {8, 2, 9, 4, 7, 6, 5, 3, 1};
    int i;
    for (i= 0; i < len; i++)
    {
       printf("%d ", arr[i]) ;
    }
    printf("\n数字开始翻转\n");
    for ( i = 0; i < len; i++)
    {
        // list_node_tail_add(new_node(arr[i]), hl);
        list_node_add(new_node(arr[i]), hl);
    }
    
    show_list(hl);
    
    return 0;
}

int del_node(int data, struct node * list)
{
    struct node * pos=list->next, *pre ;
    for(; pos!=NULL; pre = pos, pos=pos->next)
    {
        if (pos->data == data)
            break;
    }

    pre->next = pos->next;
    
    free(pos);
    return 0;

}

int list_node_tail_add(struct node *n_node, struct node * list)
{
    struct node *pos;
    for(pos = list; pos->next != NULL; pos = pos->next);

    n_node->next = pos->next;
    pos->next = n_node;

    return 0;
}

int list_node_add(struct node *n_node, struct node * list)
{
    n_node->next = list->next;
    list->next = n_node;
    return 0;
}

struct node * list_init(void)
{
    struct node *head = malloc(sizeof(struct node));
    if(head == NULL)
    {
        printf("malloc fialed!");
        return NULL;
    }
    head->next = NULL;
    return head;

}

struct node * new_node(int data)
{
    struct node *list_node = malloc(sizeof(struct node));

    list_node->data = data;
    list_node->next = NULL;

    return list_node;
}

void show_list(struct node *list)
{
    struct node *pos;
    for (pos=list->next; pos != NULL; pos=pos->next)
    {
        printf("%d ", pos->data);
    }
    printf("\n");

}

