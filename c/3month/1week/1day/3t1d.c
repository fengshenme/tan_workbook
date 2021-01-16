#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



typedef struct node
{
    int acd;   
} node_v;

typedef struct node_manger
{
    int lp;

    struct node * n;
} v_node_manger;


int main(int argc, char const *argv[])
{
    

     node_v *nv= malloc(sizeof(node_v));
    
    nv->acd = 1002343423;


    v_node_manger *vm= malloc(sizeof(v_node_manger));

    vm->lp = 66666666;
    vm->n = nv;

     printf("big:%d min:%d\n", vm->lp, vm->n->acd);

    sleep(1);
    free(vm);

    sleep(3);
    printf("min:%d\n", nv->acd);

   

    return 0;
}
