#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "include/list.h"
#include "include/sqlite3.h"

typedef struct userNode
{
    char id[12];             //实际用11位ID号加一个'\0'一共12个字节
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

int add_user(u_node *c, sqlite3 *ppdb); //增加
void searchall(); // 查找全部
int updata_user(u_node *c, sqlite3 *db);  //更新一个用户
int delete_user(sqlite3 *ppdb, char *id);  //删除一个用户

int urand(int max, int min);

void show_list(u_list ulist); // 显示列表并清空列表
int test_update(sqlite3 *db); // 测试更新
int add_test(sqlite3 *cdb); // 测试添加

static int findall(void *para, int colCount, char **columnVal, char **columnName)
{

    u_node *c = malloc(sizeof(u_node));

    bzero(c, sizeof(u_node));
    strncpy(c->id, columnVal[0], strlen(columnVal[0]));
    strncpy(c->name, columnVal[1], strlen(columnVal[1]));
    strncpy(c->password, columnVal[2], strlen(columnVal[2]));
    strncpy(c->phone, columnVal[3], strlen(columnVal[3]));
    c->status = atoi(columnVal[4]);
    c->account = atoi(columnVal[5]);
    c->vipclass = atoi(columnVal[6]);

    u_list ulist = (u_list)para;

    list_add(&c->head, &ulist->head);

    // int i;
    // for (i = 0; i < colCount; i++)
    // {
    //     printf("[%s = %s]", columnName[i], columnVal[i] ? columnVal[i] : "NULL");
    // }
    // printf("\n");

    // int ret = send(fd, &c, sizeof(c), 0);
    // if (-1 == ret)
    // {
    // fprintf(stderr, "[%d] send error\n", __LINE__);
    // }

    return 0;
}

int main(int argc, char const *argv[])
{

    sqlite3 *pdb = InitDataBase();

    u_node *hlist = malloc(sizeof(u_node));

    bzero(hlist, sizeof(u_node));
    INIT_LIST_HEAD(&hlist->head);

    searchall(pdb, hlist);
    show_list(hlist);

    delete_user(pdb, "16067905660");

    searchall(pdb, hlist);
    show_list(hlist);

    sqlite3_close(pdb); // 关闭数据库连接

    free(hlist);

    return 0;
}

int test_update(sqlite3 *db)
{
    u_node unode;
    bzero(&unode, sizeof(u_node));
    strcpy(unode.name, "b");
    strcpy(unode.phone, "15898023890");
    strcpy(unode.id, "16067905662");
    updata_user(&unode, db);
    return 0;
}

int add_test(sqlite3 *cdb)
{
    u_node *user = malloc(sizeof(u_node));
    char sid[11];

    strncpy(user->name, "assa", sizeof(user->name));
    strncpy(user->password, "1234545", sizeof(user->password));
    strncpy(user->phone, "12345678001", sizeof(user->phone));
    user->status = 0;
    user->account = 0;
    user->vipclass = 0;

    int i;
    for (i = 0; i < 6; i++)
    {
        bzero(sid, 11);
        sprintf(sid, "%ld%d", time(0), i); //11位的id当前时间秒数加一位随机数

        strncpy(user->id, sid, strlen(sid));
        add_user(user, cdb);
    }

    free(user);
    return 0;
}

// 生成min-(max+min)之间的一个随机数
int urand(int max, int min)
{
    srand((int)time(0));
    return min + (unsigned int)((float)max * rand() / (RAND_MAX + 1.0));
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
                    "id char(20) primary key not null ,name char(50) not null ,"
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
    char *zErrMsg = 0;
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
    sprintf(sql, "insert into user values (\"%s\",\"%s\",\"%s\",\"%s\",\"%hd\",\"%d\",\"%u\");",
            c->id, c->name, c->password, c->phone, c->status, c->account, c->vipclass);

    fprintf(stderr, "[%d]%s\n", __LINE__, sql);
    ret = sqlite3_exec(ppdb, sql, NULL, NULL, &zErrMsg);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "[%d] sqlite3_exec SQL error: %s\n", __LINE__, zErrMsg);
        sqlite3_free(zErrMsg);
    }

    return 0;
}

void searchall(sqlite3 *ppdb, u_list ulist)
{
    int ret;
    char *zErrMsg = 0;

    char sql[128] = "select * from user ";
    ret = sqlite3_exec(ppdb, sql, findall, ulist, &zErrMsg);

    if (ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s--%s\n", sqlite3_errmsg(ppdb), zErrMsg);
        exit(1);
    }
    return;
}

void show_list(u_list ulist)
{
    printf("num\tid\tname\tpassword\tphone\t\tstatus\taccount\tvipclass\n");
    u_list tmp, n;
    int i = 0;
    list_for_each_entry_safe(tmp, n, &ulist->head, head)
    {
        printf("[%d]%s\t%s\t%s\t\t%s\t%hd\t%d\t%d\n", ++i, tmp->id, tmp->name, tmp->password,
               tmp->phone, tmp->status, tmp->account, tmp->vipclass);
        list_del(&tmp->head);
        free(tmp);
    }
    printf("\n");
    return;
}

int updata_user(u_node *c, sqlite3 *db)
{
    int ret;
    char sql[128] = {0};

    sprintf(sql, "update user set name = '%s', phone = '%s' where id = '%s';", c->name, c->phone, c->id);
    ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s\n", sqlite3_errmsg(db));
    }
    return 0;
}

int delete_user(sqlite3 *ppdb, char *id)
{
    int ret;
    char sql[128] = {0};
    sprintf(sql, "delete from user where id = '%s';", id);
    ret = sqlite3_exec(ppdb, sql, NULL, NULL, NULL);
    if (ret != SQLITE_OK)
    {
        printf("sqlite3_exec:%s\n", sqlite3_errmsg(ppdb));
    }

    return 0;
}
