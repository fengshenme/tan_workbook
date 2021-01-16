#include <stdio.h>
#include <stdlib.h> // 默认在系统目录查找头文件
#include <time.h>

#include "list.h" // 默认在当前目录查找头文件，或者在系统目录查找

// 声明一个内核链表节点结构体（俗称：大结构体）
typedef struct kernel_list
{
    // 1.数据域
    int data;

    // 2.指针域（俗称：小结构体）
    struct list_head list; //（前后关系）
} kl_st, *kl_pt;

/**
 * @brief 初始化内核链表
 * 
 * @return kl_pt 
 */
kl_pt kl_list_init(void);
/**
 * @brief 创建新节点
 * 
 * @param data 
 * @return kl_pt 
 */
kl_pt new_node(int data);
/**
 * @brief 添加数据到链表头 new_node节点到head节点之后
 * 
 * @param new_node 
 * @param head 
 * @return int 
 */
int kl_list_add(kl_pt new_node, kl_pt head);
/**
 * @brief 添加数据到链表尾 添加new_node节点到head节点之前
 * 
 * @param new_node 
 * @param head 
 * @return int 
 */
int kl_list_add_tail(kl_pt new_node, kl_pt head);
/**
 * @brief 
 * 
 * @param data 
 * @param head 
 * @return int 
 */
int kl_list_del(int data, kl_pt head);
/**
 * @brief 安全的根据data查找到指定的数据节点然后删除, list_for_each_entry_safe
 * 
 * @param data 
 * @param head 
 * @return int 
 */
int kl_list_entry_del_safe(int data, kl_pt head);
/**
 * @brief 根据data数值查找到节点后把节点移动到head节点之后
 * 
 * @param data 
 * @param head 
 * @return int 
 */
int kl_list_move(int data, kl_pt head);
/**
 * @brief 根据data数值查找到list节点后移动到head节点之前
 * 
 * @param data 
 * @param head 
 * @return int 
 */
int kl_list_move_tail(int data, kl_pt head);
/**
 * @brief 打印链表所有数据（后序遍历）
 * 
 * @param head 
 */
void kl_list_show(kl_pt head);
/**
 * @brief 打印链表所有数据（前序遍历）
 * 
 * @param head 
 */
void kl_list_show_prev(kl_pt head);
/**
 * @brief 合并链表
 * 
 * @param list 
 * @param head 
 * @return int 
 */
int kl_list_splice(kl_pt list, kl_pt head);
/**
 * @brief 合并链表
 * 
 * @param new_node 
 * @param head 
 * @return int 
 */
int kl_list_sort_add_tail(kl_pt new_node, kl_pt head);
/**
 * @brief 先奇数升序后偶数降序 排序
 * 
 * @param head 链表起始头
 */
void kl_odd_even_sort(kl_pt head);

/**
 * @brief 先偶数降序后奇数升序
 * 
 * @param head 链表起始头部
 */
void kl_even_odd_sort(kl_pt head);
void sort(kl_pt head);

int main(int argc, char const *argv[])
{

    // 2.操作
    int n;
    while (1)
    {
        fprintf(stderr, "Pls Input: ");
        scanf("%d", &n);
        while (getchar() != '\n')
            ;
        // 1.初始化一条内核链表（头节点）
        kl_pt head = kl_list_init();

        int i, j;
        srand((int)time(0));
        for (i = 1; i <= n; i++)
        {
            j = rand() % n;
            kl_list_add_tail(new_node(j), head);
        }
        kl_list_show(head);
        sort(head);
        kl_list_show(head);
    }

    return 0;
}

void sort(kl_pt head)
{

 
}

void sort_a(int *arr, int count)
{
    int tmp, i, j;
    for (i = 0; i < count - 1; i++)
    {
        for (j = 0; j < count - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}
void kl_odd_even_sort(kl_pt head)
{
    kl_pt pos, n;
    list_for_each_entry_prev_safe(pos, n, &head->list, list)
    {
        if (pos->data % 2 == 0)
        {
            list_move_tail(&pos->list, &head->list);
        }
    }
}

void kl_even_odd_sort(kl_pt head)
{
    kl_pt pos, n;
    list_for_each_entry_safe(pos, n, &head->list, list)
    {
        if (pos->data % 2 == 0)
        {
            list_move(&pos->list, &head->list);
        }
    }
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
