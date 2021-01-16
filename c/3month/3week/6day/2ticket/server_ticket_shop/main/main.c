#include "../include/head.h"

int main(int argc, char const *argv[]) // /.server.out 端口号
{

    // const char *port = "6868";
    if (argc != 2)
    {
        fprintf(stderr, "[%d] %s <port> \n", __LINE__, argv[0]);
        exit(EXIT_FAILURE);
    }

    // //用户链表起始
    u_list list_u = malloc(sizeof(u_node));

    bzero(list_u, sizeof(u_node));
    INIT_LIST_HEAD(&list_u->head);

    // load_user(list_u);

    //航班链表起始
    f_list list_f = malloc(sizeof(f_node));

    // load_ticket(list_f);
    //已购买航班链表起始
    bfn_list list_b = malloc(sizeof(bfn));
    // load_buy_bill(list_b);

    int so_fd = init_sock(argv[1]);

     bzero(list_f, sizeof(f_node));
    INIT_LIST_HEAD(&list_f->head);

     bzero(list_b, sizeof(b_node));
    INIT_LIST_HEAD(&list_b->head);

    //大结构体链表起始
    cp_list c_list = malloc(sizeof(c_node));

    c_list->flist = list_f;
    c_list->ulist = list_u;
    c_list->blist = list_b;

    sqlite3 *db = InitDataBase();
    c_list->pdb = db;

    sql_load_user(db, list_u);
    sql_load_ticket(db, list_f);

    add_thread(so_fd, c_list);

    // Close the Connection
    close(so_fd);
    // free(list_f);
    free(list_u);
    // free(list_b);

    sqlite3_close(db);

    return 0;
}