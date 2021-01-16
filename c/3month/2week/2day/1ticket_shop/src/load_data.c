#include "head.h"


// int init_head()
// {


//     return 0;
// }

int load_user( u_list list_u)
{

    pthread_mutex_t um = list_u->m;

    // 加锁
    pthread_mutex_lock(&um);
    int usfd = open("data/user_db.txt", O_RDWR | O_CREAT, 0666);
    if (usfd < 0)
    {
        printf("[%d] open file failed\n", __LINE__);
        exit(EXIT_FAILURE);
        /* code */
    }

    char *buf = malloc(sizeof(u_node));
    char tmp[1024];
    int ret = 0;
    memset(buf, 0, sizeof(u_node));
    while (1)
    {
        memset(tmp, 0, 1);
        ret = read(usfd, tmp, 1);

        strncat(buf, tmp, 1);
        if (tmp[0] == '\n')
        {
            u_node *node = malloc(sizeof(u_node));
            //
            char *p = strtok(buf, ",");
            strncpy(node->name, p, 20);
            p = strtok(NULL, ",");
            strncpy(node->password, p, 20);
            p = strtok(NULL, ",");
            strncpy(node->phone, p, 20);

            node->m = um;

            // printf("[%d]name: %s password: %s\n", __LINE__, node->name, node->password);

            list_add(&node->head, &list_u->head);
            
            memset(buf, 0, sizeof(u_node));
        }

        if (ret <= 0)
        {
            break;
        }
    }
    close(usfd);

    // 解锁
    pthread_mutex_unlock(&um);
}

int load_ticket(f_list list_f)
{



     pthread_mutex_t fm = list_f->m;
    // 加锁
    pthread_mutex_lock(&fm);
    int fsfd = open("data/flight_info.txt", O_RDWR | O_CREAT, 0666);
    if (fsfd < 0)
    {
        printf("[%d] open file failed\n", __LINE__);
        exit(EXIT_FAILURE);
        /* code */
    }

    char *buf = malloc(sizeof(f_node));
    char tmp[1024];
    int ret = 0;
    memset(buf, 0, sizeof(f_node));
    while (1)
    {
        memset(tmp, 0, 1);

        ret = read(fsfd, tmp, 1);
        strncat(buf, tmp, 1);
        if (tmp[0] == '\n')
        {

            f_node *node = malloc(sizeof(f_node));
            bzero(node, sizeof(f_node));
            //
            char *p = strtok(buf, ",");
            strncpy(node->flight_number, p, 20);
            p = strtok(NULL, ",");
            strncpy(node->Starting, p, 20);
            p = strtok(NULL, ",");
            strncpy(node->destin, p, 20);
            p = strtok(NULL, ",");
            strncpy(node->Address, p, 10);
            p = strtok(NULL, ",");
            strncpy(node->type, p, 1);
            p = strtok(NULL, ",");
            strncpy(node->boardingTime, p, 10);
            p = strtok(NULL, ",");
            node->price = atoi(p);
            p = strtok(NULL, ",");
            node->surplusVote = atoi(p);

            node->m = fm;
            // printf("[%d]name: %s password: %d\n", __LINE__, node->flight_number, node->surplusVote);
             list_add(&node->head, &list_f->head);
            memset(buf, 0, sizeof(f_node));
        }

        if (ret <= 0)
        {
            break;
        }
    }
    close(fsfd);

    // 解锁
    pthread_mutex_unlock(&fm);
}
