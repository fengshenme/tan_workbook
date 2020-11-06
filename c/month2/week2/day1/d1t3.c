/**
 * @file d1t3.c
 * @author tan wei feng (1015956962@163.com)
 * @brief 使用链式栈，实现10进制数转换为8进制和16进制数
 * @version 0.1
 * @date 2020-10-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node
{
    int data; // 数据域

    struct stack_node *next;  //指针域

} st_node, *st_list;


/**
 * @brief 链式栈初始化
 * 
 * @return st_list 
 */
st_list st_init(void);
/**
 * @brief 压栈
 * 
 * @param n 
 * @param top 
 * @return int 
 */
int stack_push(int n, st_list top);
/**
 * @brief 弹栈
 * 
 * @param n 
 * @param top 
 * @return int 
 */
int stack_pop(int *n, st_list top);
/**
 * @brief 转换为8进制数
 * 
 * @param data 要转换的十进制数
 * @param top 
 * @return int 
 */
int shift8(int data, st_list top);
/**
 * @brief 转换为16进制数
 * 
 * @param data 要转换的十进制数
 * @param top 
 * @return int 
 */
int shift16(int data, st_list top);

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n); while (getchar() != '\n');
    st_list st_top = st_init();
    shift8(n, st_top);
    shift16(n, st_top);

    return 0;
}

int shift16(int data, st_list top)
{
    int tmp = data;

    while (tmp != 0)
    {
        // 压栈
        stack_push(tmp % 16, top);
        tmp = tmp / 16;
    }
    if (top->next == NULL)
    {
        printf("shift16 push stack fialed!\n");
        return 1;
    }

    printf("16进制数: 0x");
    while (top->next != NULL)
    {
        int n;
        stack_pop(&n, top);
        printf("%d", n);
    }
    printf("\n");

    return 0;
}

int shift8(int data, st_list top)
{

    int tmp = data;

    while (tmp != 0)
    {
        // 压栈
        stack_push(tmp % 8, top);
        tmp = tmp / 8;
    }
    if (top->next == NULL)
    {
        printf("shift8 push stack fialed!\n");
        return 1;
    }

    printf("8进制数: 0");
    while (top->next != NULL)
    {
        int n;
        stack_pop(&n, top);
        printf("%d", n);
        // sprintf(s, "%d", n);
    }
    printf("\n");
    return 0;
}

// 初始化
st_list st_init()
{
    st_list stack_init = malloc(sizeof(st_node));

    if (stack_init == NULL)
    {
        printf("malloc fialed! \n");
        return NULL;
    }

    stack_init->next = NULL;

    return stack_init;
}

// 弹栈
int stack_pop(int *n, st_list top)
{
    if (top->next == NULL)
    {
        printf("Empty stack!\n");
        return 1;
    }

    *n = top->next->data;
    st_list tmp = top->next;
    top->next = top->next->next;
    free(tmp); //回收内存
    return 0;
}
// 压栈
int stack_push(int n, st_list top)
{
    st_list n_node = malloc(sizeof(st_node));
    n_node->data = n;
    n_node->next = top->next;
    top->next = n_node;
    return 0;
}