#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;

    struct node *next;
};

struct node *new_node(int data, void *next);

//添加节点在头部
int node_add(struct node *n_node, struct node *node_list);
//添加节点在链尾
int node_add_tail(struct node *n_node, struct node *node_list);
//初始化空链表
struct node *list_init(void);
//删除节点
int del_node(int data, struct node *list);
//打印链表
void list_show(struct node *head);

int main(int argc, char const *argv[])
{

    struct node *head = list_init();

    int num;

    while (1)
    {
        scanf("%d", &num);
        while (getchar() != '\n')
            ;

        if (num > 0)
        {
            struct node *n_node = new_node(num, NULL);
            // node_add(n_node, head);
            node_add_tail(n_node, head);
        }
        else if (num < 0)
        {
            del_node(-num, head);
        }
        list_show(head);
    }

    return 0;
}

//添加节点在链尾
int node_add_tail(struct node *n_node, struct node *node_list)
{

    struct node *pos;
    for (pos = node_list; pos->next != NULL; pos = pos->next);
    n_node->next = pos->next;
    pos->next = n_node;
    return 0;
}

int del_node(int data, struct node *list)
{
    if (list->next == NULL)
    {
        printf("Empty\n");
        return 1;
    }
    struct node *pos = list->next, *pre = list;
    for (; pos != NULL; pre = pos, pos = pos->next)
    {
        if (pos->data == data)
            break;
    }

    if (pos == NULL)
    {
        printf("not find!\n");
        return 1;
    }
    pre->next = pos->next;
    free(pos);

    return 0;
}

struct node *list_init(void)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->next = NULL;
    return new_node;
}

struct node *new_node(int data, void *next)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = next;

    return new_node;
}

int node_add(struct node *n_node, struct node *node_list)
{

    n_node->next = node_list->next;
    node_list->next = n_node;
    return 0;
}

void list_show(struct node *head)
{
    struct node *pos;
    for (pos = head->next; pos != NULL; pos = pos->next)
    {
        printf("%d ", pos->data);
    }
    printf("\n");
}