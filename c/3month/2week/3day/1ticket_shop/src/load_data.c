#include "head.h"

// int init_head()
// {

//     return 0;
// }

int open_file(int *fd, const char *path)
{
    *fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0666);
    if (*fd < 0)
    {
        printf("[%d] open file failed\n", __LINE__);
        exit(EXIT_FAILURE);
    }
    return 0;
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
    int usfd;
    open_file(&usfd, "data/user_db.txt");

    char *buf = malloc(sizeof(u_node));
    char tmp[1024];
    int ret = 0;
    memset(buf, 0, sizeof(u_node));
    int count = 0;
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
            if (p != NULL)
                strncpy(node->name, p, 20);
            p = strtok(NULL, ",");
            if (p != NULL)
                strncpy(node->password, p, 20);
            p = strtok(NULL, ",");
            if (p != NULL)
                strncpy(node->phone, p, 20);
            p = strtok(NULL, ",");
            if (p != NULL)
                node->status = atoi(p);
            node->m = um;

            // printf("[%d]name: %s password: %d\n", __LINE__, node->name, node->status);

            list_add(&node->head, &list_u->head);
            count++;
            memset(buf, 0, sizeof(u_node));
        }

        if (ret <= 0)
        {
            printf("[%d]load user data: %d row\n", __LINE__, count);
            break;
        }
    }
    close(usfd);

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
    int fsfd;
    open_file(&fsfd, "data/flight_info.txt");

    char *buf = malloc(sizeof(f_node));
    char tmp[1024];
    int ret = 0;
    memset(buf, 0, sizeof(f_node));
    int count = 0;
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
                strncpy(node->type, p, 1);
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
            // printf("[%d]name: %s password: %d\n", __LINE__, node->flight_number, node->surplusVote);
            list_add(&node->head, &list_f->head);
            count++;
            memset(buf, 0, sizeof(f_node));
        }

        if (ret <= 0)
        {
            printf("[%d]load flight data: %d row\n", __LINE__, count);
            break;
        }
    }
    close(fsfd);

    // 解锁
    pthread_mutex_unlock(&fm);

    return 0;
}
