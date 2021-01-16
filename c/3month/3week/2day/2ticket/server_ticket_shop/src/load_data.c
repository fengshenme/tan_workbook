#include "../include/head.h"

// int init_head()
// {

//     return 0;
// }

FILE *open_file(const char *path)
{
    FILE *fd = fopen(path, "a+");
    if (fd == NULL)
    {
        printf("[%d] open file failed\n", __LINE__);
        exit(EXIT_FAILURE);
    }
    return fd;
}

int load_user(u_list list_u)
{

    // 初始化头结点
    INIT_LIST_HEAD(&list_u->head);

    pthread_mutex_t um;
    pthread_mutex_init(&um, NULL);

    list_u->m = um;

    // 加锁
    pthread_mutex_lock(&um);
    FILE *usfd = open_file("data/user_db.txt");

    char *buf = malloc(sizeof(u_node));

    int count = 0;

    while (fgets(buf, 1024, usfd) != NULL)
    {

        u_node *node = malloc(sizeof(u_node));
        //
        char *p = strtok(buf, ",");
        if (p != NULL)
            strncpy(node->name, p, 20);
        p = strtok(NULL, ",");
        if (p != NULL)
            strncpy(node->password, p, 20);
        p = strtok(NULL, ",");
        if (p != NULL)
            strncpy(node->phone, p, 13);
        p = strtok(NULL, ",");
        if (p != NULL)
            node->status = atoi(p);
        p = strtok(NULL, ",");
        if (p != NULL)
            node->account = atoi(p);
        p = strtok(NULL, ",");
        if (p != NULL)
            node->vipclass = atoi(p);
        node->m = um; 
        // printf( "%d=>%s-%d\n", __LINE__, p, atoi(p));
        // printf( "%d=>%s,%s,%s,%hd,%d,%u\n", __LINE__, node->name, node->password, node->phone, node->status, node->account, node->vipclass);
                

        list_add(&node->head, &list_u->head);
        count++;
        memset(buf, 0, sizeof(u_node));
    }
    printf("[%d]load user data: %d row\n", __LINE__, count);
    fclose(usfd);

    // 解锁
    pthread_mutex_unlock(&um);
    return 0;
}

int load_ticket(f_list list_f)
{

    // 初始化头结点
    INIT_LIST_HEAD(&list_f->head);

    pthread_mutex_t fm;
    pthread_mutex_init(&fm, NULL);
    list_f->m = fm;

    // 加锁
    pthread_mutex_lock(&fm);
    FILE *fsfd = open_file("data/flight_info.txt");

    char *buf = malloc(sizeof(f_node));
    memset(buf, 0, sizeof(f_node));
    int count = 0;
    while (fgets(buf, sizeof(f_node), fsfd) != NULL)
    {
        f_node *node = malloc(sizeof(f_node));
        bzero(node, sizeof(f_node));
        //
        // printf("[%d]%s",__LINE__, buf);
        char *p ;
        p= strtok(buf, ",");
        if (p != NULL)
            strncpy(node->flight_number, p, 20);
        p = strtok(NULL, ",");
        if (p != NULL)
            strncpy(node->Starting, p, 20);
        p = strtok(NULL, ",");
        if (p != NULL)
            strncpy(node->destin, p, 20);
        p = strtok(NULL, ",");
        if (p != NULL)
            strncpy(node->Address, p, 10);
        p = strtok(NULL, ",");
        if (p != NULL)
            node->ftype = *p;
        p = strtok(NULL, ",");
        if (p != NULL)
            strncpy(node->boardingTime, p, 10);
        p = strtok(NULL, ",");
        if (p != NULL)
            node->price = atoi(p);
        p = strtok(NULL, ",");
        if (p != NULL)
            node->surplusVote = atoi(p);

        node->m = fm;
        // printf("[%d]%s,%s,%s,%s,%c,%s,%u,%u\n",__LINE__, node->flight_number, node->Starting,
        //         node->destin, node->Address, node->type, node->boardingTime, node->price, node->surplusVote);
        list_add(&node->head, &list_f->head);
        count++;
        memset(buf, 0, sizeof(f_node));
    }
    printf("[%d]load user data: %d row\n", __LINE__, count);

    fclose(fsfd);

    // 解锁
    pthread_mutex_unlock(&fm);

    return 0;
}

int load_buy_bill(bfn_list blist)  // 加载票据信息
{
    // 初始化头结点
    INIT_LIST_HEAD(&blist->head);

    pthread_mutex_t bm;
    pthread_mutex_init(&bm, NULL);
    blist->m = bm;

    // 加锁
    pthread_mutex_lock(&bm);
    FILE *blfd = open_file("data/buy_flight_db.txt");

    char *buf = malloc(sizeof(u_node));

    int count = 0;

    while (fgets(buf, 1024, blfd) != NULL)
    {

        bfn *node = malloc(sizeof(bfn));
        //
        char *p = strtok(buf, ",");
        if (p != NULL)
            strncpy(node->phone, p, 13);
        p = strtok(NULL, ",");
        if (p != NULL)
            strncpy(node->flight_number, p, 10);
        p = strtok(NULL, ",");
        if (p != NULL)
            strncpy(node->Address, p, 10);
        p = strtok(NULL, ",");
        if (p != NULL)
            node->price = atoi(p);
        p = strtok(NULL, ",");
        if (p != NULL)
            node->flags = atoi(p);
        
        node->m = bm; 
        // printf( "%d=>%s-%d\n", __LINE__, p, atoi(p));
        // printf( "%d=>%s,%s,%s,%u,%u\n", __LINE__, node->phone, node->flight_number, node->Address, node->price, node->flags);

        list_add(&node->head, &blist->head);
        count++;
        memset(buf, 0, sizeof(bfn));
    }
    printf("[%d]load buy count data: %d row\n", __LINE__, count);
    fclose(blfd);

    // 解锁
    pthread_mutex_unlock(&bm);
    return 0;
}


