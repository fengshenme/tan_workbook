#include "../include/head.h"

int main(int argc, char const *argv[]) // /.server.out 端口号
{

        // const char *port = "6868";
    if (argc != 2)
    {
        fprintf(stderr, "[%d] %s <port> \n", __LINE__, argv[0]);
        exit(EXIT_FAILURE);
    }

    //用户链表起始
    u_list list_u = malloc(sizeof(u_node));

    load_user(list_u);

    //航班链表起始
    f_list list_f = malloc(sizeof(f_node));

    load_ticket(list_f);
    //已购买航班链表起始
    bfn_list list_b = malloc(sizeof(bfn));
    load_buy_bill(list_b);

    int so_fd = init_sock(argv[1]);

    //大结构体链表起始
    cp_list c_list = malloc(sizeof(c_node));

    c_list->flist = list_f;
    c_list->ulist = list_u;
    c_list->blist = list_b;

    add_thread(so_fd, c_list);

    // Close the Connection
    close(so_fd);
    free(list_f);
    free(list_u);
    free(list_b);

    return 0;
}