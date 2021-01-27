#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#include "include/list.h"
#include "include/sqlite3.h"

typedef struct userNode
{
    char id[11];
    char name[20];           // 用户名
    char password[20];       // 密码
    char phone[13];          //手机号
    short status;            // 0是未登录下线状态, 1是登录状态
    int account;             // 账户余额
    unsigned short vipclass; //vip等级

    pthread_mutex_t m;

    struct list_head head; // 内核链表

} * u_list, u_node;

sqlite3 *InitDataBase();

int add_user(u_node *c, sqlite3 *ppdb);
int urand(int n);
void search();
static int sendinfo(void *para, int columnCount, char *columnVal[], char *columnName[]);
int add_test(sqlite3 *cdb);

int main(int argc, char const *argv[])
{
    
    sqlite3 *pdb = InitDataBase();

    add_test(pdb);
    search(pdb);

    sqlite3_close(pdb);

    return 0;
}

int add_test(sqlite3 *cdb)
{
    u_node *user = malloc(sizeof(u_node));
    char sid[11];
    unsigned long idi = time(0);
    int a = urand(10);
    sprintf(sid, "%ld%d", idi, a); //11位的id当前时间秒数加一位随机数
    strncpy(user->id, sid, sizeof(11));
    printf("[%d] %ld : %s : %d\n", __LINE__, idi, sid, a);
    strncpy(user->name, "asssda", sizeof(user->name));
    strncpy(user->password, "1234545", sizeof(user->password));
    strncpy(user->phone, "12345678001", sizeof(user->phone));
    user->status = 0;
    user->account = 0;
    user->vipclass = 0;

    add_user(user, cdb);
    free(user);
    return 0;
}

// 生成0-n之间的一个随机数
int urand(int n)
{
    srand((int)time(0));
    return 1 + (unsigned int)((float)n * rand() / (RAND_MAX + 1.0));
}

sqlite3 *InitDataBase()
{

    sqlite3 *pdb; //数据库句柄

    int ret = sqlite3_open("ticketing.db", &pdb);

    if (ret)
    {
        printf("sqlite3_open : %s\n", sqlite3_errmsg(pdb));

        return NULL;
    }

    // sql语句-如果表不存在就创建表
    char sql[256] = "CREATE TABLE if not exists user ("
                    "id int primary key not null ,name char(50) not null ,"
                    "password char(50) not null , phone char(50) not null ,"
                    "status int not null , account int not null ,  vipclass int not null) ;";

    ret = sqlite3_exec(pdb, sql, NULL, NULL, NULL);

    char *zErrMsg = 0;
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "[%d] sqlite3_exec SQL error: %s\n", __LINE__, zErrMsg);
        sqlite3_free(zErrMsg);
    }

    

    return pdb;
}

int add_user(u_node *c, sqlite3 *ppdb)
{
    int ret;

    /*
    int id;
    char name[20];     // 用户名
    char password[20]; // 密码
    char phone[13];    //手机号
    short status; // 0是未登录下线状态, 1是登录状态
    int account;             // 账户余额
    unsigned short vipclass; //vip等级
    */
    char sql[256] = {0};
    sprintf(sql, "insert into user values ('%s','%s','%s','%s','%hd','%d','%u');", c->id, c->name,
            c->password, c->phone, c->status, c->account, c->vipclass);
    ret = sqlite3_exec(ppdb, sql, NULL, NULL, NULL);

    char *zErrMsg = 0;
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "[%d] sqlite3_exec SQL error: %s\n", __LINE__, zErrMsg);
        sqlite3_free(zErrMsg);
    }

    return 0;
}

static int sendinfo(void *para, int colCount, char **columnVal, char **columnName)
{

    u_node *c = (u_node *)para;

    strcpy(c->id, columnVal[0]);
    strcpy(c->name, columnVal[1]);
    strcpy(c->password, columnVal[2]);
    strcpy(c->phone, columnVal[3]);
    c->status = atoi(columnVal[4]);
    c->account = atoi(columnVal[5]);
    c->vipclass = atoi(columnVal[6]);

    int i;
    for (i = 0; i < colCount; i++)
    {
        printf("%s = %s\n", columnName[i], columnVal[i] ? columnVal[i] : "NULL");
    }
    printf("\n");

    // int ret = send(fd, &c, sizeof(c), 0);
    // if (-1 == ret)
    // {
    // fprintf(stderr, "[%d] send error\n", __LINE__);
    // }

    return 0;
}

void search(sqlite3 *ppdb)
{
    int ret ;
    
    u_node unode;
    bzero(&unode, sizeof(u_node));

    char sql[128] = {0};
    sprintf(sql, "select * from user ");
    ret = sqlite3_exec(ppdb, sql, sendinfo, &unode, NULL);
    if (ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s\n", sqlite3_errmsg(ppdb));
        exit(1);
    }

    printf("id\tname\tpassword\tphone\t\tstatus\taccount\tvipclass\n");
    printf("%s\t%s\t%s\t%s\t\t%hd\t%d\t%d\n", unode.id, unode.name, unode.password, unode.phone, unode.status, unode.account, unode.vipclass);
}

// void updata_info(u_node *c)
// {
//     sqlite3 *ppdb;
//     int ret = sqlite3_open("address.db", &ppdb);
//     if (ret != SQLITE_OK)
//     {
//         printf("sqlite3_open : %s\n", sqlite3_errmsg(ppdb));
//     }

//     char sql[128] = {0};
//     sprintf(sql, "update address set name = '%s',tel = '%s' where name = '%s';", c->name, c->tel, c->old_name);
//     ret = sqlite3_exec(ppdb, sql, NULL, NULL, NULL);
//     if (ret != SQLITE_OK)
//     {
//         printf("sqlite3_exec:%s\n", sqlite3_errmsg(ppdb));
//     }
//     sqlite3_close(ppdb);
// }

// void delete_info(u_node *c)
// {
//     sqlite3 *ppdb;
//     int ret = sqlite3_open("address.db", &ppdb);
//     if (ret != SQLITE_OK)
//     {
//         printf("sqlite3_open : %s\n", sqlite3_errmsg(ppdb));
//     }

//     char sql[128] = {0};
//     sprintf(sql, "delete from address where name = '%s';", c->name);
//     ret = sqlite3_exec(ppdb, sql, NULL, NULL, NULL);
//     if (ret != SQLITE_OK)
//     {
//         printf("sqlite3_exec:%s\n", sqlite3_errmsg(ppdb));
//     }
//     sqlite3_close(ppdb);
// }
