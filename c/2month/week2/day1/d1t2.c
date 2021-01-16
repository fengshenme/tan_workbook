#include <stdio.h>
#include "../list.h"
#include <stdlib.h>

// 1.声明一个栈节点结构体
typedef struct stack_node
{
    // 1.数据域
    int data;

    // 2.指针域
    struct stack_node *next;
} node_st, *node_pt;

node_pt init(void);
int stack_push(int n, node_pt top);
int stack_pop(int *n, node_pt top);

int main(int argc, char const *argv[])
{
    // 1.定义一个栈顶指针  *top，使其指向NULL（链式栈初始化）
    node_pt top = init();

    int n;
    // 2.操作
    while (1)
    {
        scanf("%d", &n);
        while (getchar() != '\n')
            ;

        if (n > 0)
        {
            //压栈
            stack_push(n, top);
        }
        else if (n < 0)
        {

            int m;
            while (top->next != NULL)
            {
                //弹栈
                stack_pop(&m, top);
                printf("--->%d", m);
            }
            printf("\n");
        }
    }

    return 0;
}

int stack_pop(int *n, node_pt top)
{
    if (top->next == NULL)
    {
        printf("Empty stack!\n");
        return 1;
    }

    *n = top->next->data;
    node_pt tmp = top->next;
    top->next = top->next->next;
    free(tmp);
    return 0;
}

int stack_push(int n, node_pt top)
{
    node_pt n_node = malloc(sizeof(node_st));
    n_node->data = n;
    n_node->next = top->next;
    top->next = n_node;
    return 0;
}

node_pt init(void)
{
    node_pt top = malloc(sizeof(node_st));
    top->next = NULL;
    return top;
}
