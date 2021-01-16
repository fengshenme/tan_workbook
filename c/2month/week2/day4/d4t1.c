#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// 冒泡排序
void bubble_sort(int n, int *a);

void insertion_sort(int n, int *arr);

typedef struct node
{
    int data;

    struct list_head list;
} kl_node, *kl_pn;

kl_pn new_node(int num)
{
    kl_pn n_node = malloc(sizeof(kl_node));
    if (n_node == NULL)
    {
        perror("n_node malloc failed\n");
    }
    n_node->data = num;
    INIT_LIST_HEAD(&n_node->list);
    return n_node;
}

void show(kl_pn head)
{
    kl_pn pos;
    list_for_each_entry(pos, &head->list, list)
    {
        printf("%d ", pos->data);
    }
    printf("\n");
}

void sort2(kl_pn head)
{

    kl_pn pos, get_bign;
    struct list_head *lh, *hl;
    hl = &head->list;

    list_for_each_entry(pos, hl, list)
    {

        // for(lh = pos->list.prev ; lh != hl; lh =lh->prev)
        // {
        //     get_bign = list_entry(lh, kl_node, list);
        //     // printf("%d ", get_bign->data);
        //     // printf("%d \n", pos->data);
        //     if (get_bign->data < pos->data)
        //     {
        //         list_move(lh, &pos->list);
        //     }
        // }
        list_for_each_prev(lh, hl)
        {
            get_bign = list_entry(lh, kl_node, list);
            // printf("%d ", get_bign->data);
            // printf("%d \n", pos->data);
            if (get_bign->data < pos->data)
            {
                list_move(lh, &pos->list);
            }
        }
    }
    show(head);
}

int main(int argc, char const *argv[])
{

    kl_pn head = malloc(sizeof(kl_node));
    if (head == NULL)
    {
        printf("head malloc failed\n");
        return 0;
    }
    INIT_LIST_HEAD(&head->list);

    int arr[11] = {1, 3, 6,11, 9, 2, 8, 4, 5, 7,10};
    int i;
    for (i = 0; i < 11; i++)
    {
        list_add(&new_node(arr[i])->list, &head->list);
    }

    show(head);
    kl_pn pos, get_bign;
    struct list_head *lh;

    list_for_each_entry(pos, &head->list, list)
    {
        list_for_each_prev(lh, &head->list)
        {
            get_bign = list_entry(lh, kl_node, list);
            if (get_bign->data < pos->data)
            {
                list_move(lh, &pos->list);
            }
        }
    }
    show(head);
    insertion_sort(11, arr);
    for (size_t i = 0; i < 11; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    char c[100] = "bscss";
    char * a = c;
    printf("%d\n", a[0]);
    

    return 0;
}

void insertion_sort(int n, int *arr)
{
    int i, j;
    for (i = 1; i < n; i++)
    {
        int tmp = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > tmp)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = tmp;
    }
}

// 冒泡排序
void bubble_sort(int n, int *a)
{
    int i, j, count;
    for (i = 0; i < n - 1; i++)
    {
        count = 0;
        for (j = 0; j < n - i - 1; j++)
        {

            if (a[j] > a[j + 1])
            {
                int tmp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = tmp;
                count = 1;
            }
        }
        if (count == 0)
            break;
    }
}
