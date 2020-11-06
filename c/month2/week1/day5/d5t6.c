#include <stdio.h>
#include <stdlib.h> // 默认在系统目录查找头文件

#include "list.h" // 默认在当前目录查找头文件，或者在系统目录查找

// 声明一个内核链表节点结构体（俗称：大结构体）
typedef struct kernel_list
{
    // 1.数据域
    int data;

    // 2.指针域（俗称：小结构体）
    struct list_head list; //（前后关系）
} kl_st, *kl_pt;

// 初始化内核链表
kl_pt kl_list_init(void);
// 创建新节点
kl_pt new_node(int data);
// 添加数据到链表头 new节点到head节点之后,
int kl_list_add(kl_pt new_node, kl_pt head);
// 添加数据到链表尾 添加new节点到head节点之前
int kl_list_add_tail(kl_pt new_node, kl_pt head);
// 删除指定的数据节点
int kl_list_del(int data, kl_pt head);
// 删除指定的数据节点, list_for_each_entry_safe
int kl_list_entry_del_safe(int data, kl_pt head);
// 查找到list节点后移动到head节点之后
int kl_list_move(int data, kl_pt head);
// 查找到list节点后移动到head节点之前
int kl_list_move_tail(int data, kl_pt head);
// 打印链表所有数据（后序遍历）
void kl_list_show(kl_pt head);
// 打印链表所有数据（前序遍历）
void kl_list_show_prev(kl_pt head);
//合并链表
int kl_list_splice(kl_pt list, kl_pt head);
//递增插入
int kl_list_sort_add_tail(kl_pt new_node, kl_pt head);

int main(int argc, char const *argv[])
{
    // 1.初始化一条内核链表（头节点）
    kl_pt head = kl_list_init();

    // 2.操作
    int n;
    while (1)
    {
        fprintf(stderr, "Pls Input: ");
        scanf("%d", &n);
        while (getchar() != '\n')
            ;

        if (n > 0)
        {
            //添加
            // kl_list_add(new_node(n), head);
            kl_list_sort_add_tail(new_node(n), head);
        }
        else if (n < 0)
        {
            //删除
            kl_list_del(-n, head);
            // kl_list_entry_del_safe(-n, head);
            // 移动
            // kl_list_move(-n, head);
            // kl_list_move_tail(-n, head);
        }
        else
        {
            //退出
            printf("Bye Bye~\n");
            return 1;
        }
        kl_list_show(head);

        // kl_list_show_prev(head);
    }

    return 0;
}

// 初始化内核链表头节点
kl_pt kl_list_init(void)
{
    // 1.申请一块堆空间给头节点
    kl_pt head = malloc(sizeof(kl_st));
    if (head == NULL)
    {
        perror("head malloc failed");
        return NULL;
    }

    // 2.修改头节点的指针域，使它们都指向自身
    INIT_LIST_HEAD(&head->list);

    // 3.将堆空间首地址返回
    return head;
}

kl_pt new_node(int data)
{
    // 1.给新节点申请一块堆空间
    kl_pt new_node = malloc(sizeof(kl_st));
    if (new_node == NULL)
    {
        perror("new node malloc fialed!\n");
        return NULL;
    }

    // 2.将新数据给入数据域
    new_node->data = data;

    return new_node;
}

// 添加数据到链表头
int kl_list_add(kl_pt new_node, kl_pt head)
{

    // 3.修改指向
    list_add(&new_node->list, &head->list);

    return 0;
}

int kl_list_add_tail(kl_pt new_node, kl_pt head)
{

    // 3.修改指向
    list_add_tail(&new_node->list, &head->list);

    return 0;
}

int kl_list_sort_add_tail(kl_pt new_node, kl_pt head)
{
    kl_pt pos;
    list_for_each_entry(pos, &head->list, list)
    {
        if (pos->data > new_node->data)
            break;
    }
         
    list_add_tail(&new_node->list, &pos->list);

    return 0;
}

// 打印链表所有数据（后序遍历）
void kl_list_show(kl_pt head)
{
    struct list_head *pos;
    list_for_each(pos, &head->list)
    {
        printf("%d ", list_entry(pos, kl_st, list)->data);
    }
    printf("\n");
}

void kl_list_show_prev(kl_pt head)
{
    struct list_head *pos;

    list_for_each_prev(pos, &head->list)
    {
        printf("%d ", list_entry(pos, kl_st, list)->data);
    }
    printf("\n");
}

int kl_list_del(int data, kl_pt head)
{

    if (list_empty(&head->list))
    {
        printf("Empty!\n");
        return 1;
    }

    struct list_head *tmp, *pos;
    list_for_each_safe(pos, tmp, &head->list)
    {
        kl_pt get_node = list_entry(pos, kl_st, list);
        if (get_node->data == data)
        {
            list_del(pos);
            free(get_node);
            break;
        }
    }

    if (pos == &head->list)
    {
        perror("Not found\n");
        return 2;
    }

    return 0;
}

int kl_list_entry_del_safe(int data, kl_pt head)
{
    if (list_empty(&head->list))
    {
        printf("Empty!\n");
        return 1;
    }

    kl_pt n, pos;
    list_for_each_entry_safe(pos, n, &head->list, list)
    {
        if (pos->data == data)
        {
            list_del(&pos->list);
            free(pos);
            break;
        }
    }

    if (&(pos->list) == &(head->list))
    {
        perror("Not found\n");
        return 2;
    }

    return 0;
}

int kl_list_move(int data, kl_pt head)
{
    kl_pt pos;
    list_for_each_entry(pos, &head->list, list)
    {
        if (pos->data == data)
            break;
    }
    if (&(pos->list) == &(head->list))
    {
        perror("Not found\n");
        return 2;
    }
    list_move(&pos->list, &head->list);

    return 0;
}

int kl_list_move_tail(int data, kl_pt head)
{
    kl_pt pos;
    list_for_each_entry(pos, &head->list, list)
    {
        if (pos->data == data)
            break;
    }
    if (&(pos->list) == &(head->list))
    {
        perror("Not found\n");
        return 2;
    }
    list_move_tail(&pos->list, &head->list);
    return 0;
}

int kl_list_splice(kl_pt list, kl_pt head)
{
    list_splice(&list->list, &head->list);
    return 0;
}
