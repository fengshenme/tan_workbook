// 2.尝试根据链式队列的示意图，把实现代码完成。
#include <stdlib.h>
#include <stdio.h>

typedef struct queue_node
{
    int data;

    struct queue_node *prev;
    struct queue_node *next;
} queue_nd, *pt_queue;

int dequeue(pt_queue pt);
pt_queue init(void);
int enqueue(int data, pt_queue rear);

int main(int argc, char const *argv[])
{
    
    pt_queue top = init();

    int n;
    // 2.操作
    while (1)
    {
        scanf("%d", &n);
        while (getchar() != '\n')
            ;

        if (n > 0)
        {
            //入队
            enqueue(n, top);
        }
        else if (n < 0)
        {

            while (top->prev != top)
            {
                //出队
                dequeue( top);
            }
            printf("\n");
        }
    }


    return 0;
}

pt_queue init(void)
{
    pt_queue ue_node = malloc(sizeof(queue_nd));
    if (ue_node == NULL)
    {
        printf("init malloc fiaed\n");
        return NULL;
    }
    

    ue_node->prev = ue_node;
    ue_node->next = ue_node;

    return ue_node;
}

int enqueue(int data, pt_queue rear)
{
    pt_queue ue_node = malloc(sizeof(queue_nd));
    if (ue_node == NULL)
    {
        printf("init malloc fiaed\n");
        return 1;
    }

    ue_node->next = rear;
    ue_node->data = data;
    ue_node->prev = rear->prev;
    rear->prev = ue_node;

    return 0;

}

int dequeue(pt_queue pt)
{
    pt_queue tmp = pt->prev;

    pt->prev->prev->next = pt;
    
    pt->prev = pt->prev->prev;
    printf("%d ", tmp->data);
    free(tmp);
    return 0;
}
