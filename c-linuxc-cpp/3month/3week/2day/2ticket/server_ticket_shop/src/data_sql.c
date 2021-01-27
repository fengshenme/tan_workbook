#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../include/head.h"

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

    return 0;
}

static int all_flight(void *para, int colCount, char **columnVal, char **columnName)
{

    f_node *f = malloc(sizeof(f_node));

    bzero(f, sizeof(u_node));
    strncpy(f->id, columnVal[0], strlen(columnVal[0]));
    strncpy(f->flight_number, columnVal[1], strlen(columnVal[1]));
    strncpy(f->Starting, columnVal[2], strlen(columnVal[2]));
    strncpy(f->destin, columnVal[3], strlen(columnVal[3]));
    strncpy(f->Address, columnVal[4], strlen(columnVal[4]));
    f->ftype = columnVal[5][0];
    strncpy(f->boardingTime, columnVal[6], strlen(columnVal[6]));
    f->price = atoi(columnVal[7]);
    f->surplusVote = atoi(columnVal[8]);
    f->flags = atoi(columnVal[9]);

    f_list flist = (f_list)para;

    list_add(&f->head, &flist->head);

    return 0;
}

static int one_flight(void *para, int colCount, char **columnVal, char **columnName)
{

    f_node *f = para;

    bzero(f, sizeof(u_node));
    strncpy(f->id, columnVal[0], strlen(columnVal[0]));
    strncpy(f->flight_number, columnVal[1], strlen(columnVal[1]));
    strncpy(f->Starting, columnVal[2], strlen(columnVal[2]));
    strncpy(f->destin, columnVal[3], strlen(columnVal[3]));
    strncpy(f->Address, columnVal[4], strlen(columnVal[4]));
    f->ftype = columnVal[5][0];
    strncpy(f->boardingTime, columnVal[6], strlen(columnVal[6]));
    f->price = atoi(columnVal[7]);
    f->surplusVote = atoi(columnVal[8]);
    f->flags = atoi(columnVal[9]);

    return 0;
}

static int findone(void *para, int colCount, char **columnVal, char **columnName)
{

    u_node *node = para;

    bzero(node, sizeof(u_node));
    strncpy(node->id, columnVal[0], strlen(columnVal[0]));
    strncpy(node->name, columnVal[1], strlen(columnVal[1]));
    strncpy(node->password, columnVal[2], strlen(columnVal[2]));
    strncpy(node->phone, columnVal[3], strlen(columnVal[3]));
    node->status = atoi(columnVal[4]);
    node->account = atoi(columnVal[5]);
    node->vipclass = atoi(columnVal[6]);

    printf("%d=>%s,%s,%s,%hd,%d,%u\n", __LINE__, node->name, node->password, node->phone, node->status, node->account, node->vipclass);

    return 0;
}

// 生成min-(max+min)之间的一个随机数
int uranda(int max, int min)
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

    // sql语句-如果表不存在就创建用户表
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
    // sql语句-如果表不存在就创建航班表
    char flsql[512] = "CREATE TABLE if not exists flight_info ("
                      "id char(20) primary key not null ,flight_number char(20) not null ,"
                      "starting char(20) not null , destin char(20) not null ,"
                      "address char(20) not null , ftype char(5) not null ,"
                      "boardingtime char(20) not null , price int not null ,"
                      "surplus_vote int  , flags int not null ) ;";

    ret = sqlite3_exec(pdb, flsql, NULL, NULL, NULL);

    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "[%d] sqlite3_exec  flight_info existed or sql error: %s\n", __LINE__, zErrMsg);
        sqlite3_free(zErrMsg);
    }
    // sql语句-如果表不存在就创建航班表
    char bfsql[512] = "CREATE TABLE if not exists buy_flight_info ("
                      "id char(20) primary key not null ,flight_id char(20) not null ,"
                      "user_id char(20) not null , flags int not null ) ;";

    ret = sqlite3_exec(pdb, bfsql, NULL, NULL, NULL);

    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "[%d] sqlite3_exec  flight_info existed or sql error: %s\n", __LINE__, zErrMsg);
        sqlite3_free(zErrMsg);
    }

    return pdb;
}

int sql_buy_flight( sqlite3 *db, b_node *bnode)
{
    int ret;
    char *zErrMsg = 0;

    char sql[256] = {0};
    bnode->flags = 1;
    sprintf(sql, "insert into buy_flight_info values ('%s','%s','%s', '%u');",
            bnode->id, bnode->flight_id, bnode->user_id, bnode->flags);

    printf("[%d]:%s\n", __LINE__, sql);
    ret = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "[%d] sqlite3_exec SQL error: %s\n", __LINE__, zErrMsg);
        sqlite3_free(zErrMsg);
        return -1;
    }
    return 0;
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

    ret = sqlite3_exec(ppdb, sql, NULL, NULL, &zErrMsg);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "[%d] sqlite3_exec SQL error: %s\n", __LINE__, zErrMsg);
        sqlite3_free(zErrMsg);
    }

    return 0;
}

int sqladd_flight(f_node *f, sqlite3 *db)
{
    int ret;
    char *zErrMsg = 0;

    char sql[256] = {0};
    f->flags = 1;
    sprintf(sql, "insert into flight_info values ('%s','%s','%s','%s','%s','%c','%s','%u','%u', '%u');",
            f->id, f->flight_number, f->Starting, f->destin, f->Address, f->ftype,
            f->boardingTime, f->price, f->surplusVote, f->flags);

    printf("[%d]:%s\n", __LINE__, sql);
    ret = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);
    if (ret != SQLITE_OK)
    {
        fprintf(stderr, "[%d] sqlite3_exec SQL error: %s\n", __LINE__, zErrMsg);
        sqlite3_free(zErrMsg);
        return -1;
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
        printf("[%d]sqlite3_exec:%s--%s\n", __LINE__, sqlite3_errmsg(ppdb), zErrMsg);
        sqlite3_free(zErrMsg);
    }
    return;
}

int sql_find_fli_all(sqlite3 *ppdb, f_list flist)
{
    int ret;
    char *zErrMsg = 0;

    char sql[128] = "select * from flight_info ;";
    ret = sqlite3_exec(ppdb, sql, all_flight, flist, &zErrMsg);

    if (ret != SQLITE_OK)
    {
        printf("[%d]sqlite3_exec:%s--%s\n", __LINE__, sqlite3_errmsg(ppdb), zErrMsg);
        sqlite3_free(zErrMsg);
        return -1;
    }
    return 0;
}

int sql_find_flght_one(sqlite3 *db, f_node *fnode)
{

    int ret;
    char *zErrMsg = 0;

    char sql[128] = {0};
    sprintf(sql, "select * from flight_info where flight_number=\"%s\" and address=\"%s\" and surplus_vote>0;", fnode->flight_number, fnode->Address);
    ret = sqlite3_exec(db, sql, one_flight, fnode, &zErrMsg);
    if (ret != SQLITE_OK)
    {
        printf("[%d]sqlite3_exec:%s--%s\n", __LINE__, sqlite3_errmsg(db), zErrMsg);
        sqlite3_free(zErrMsg);
        return -1;
    }
    return 0;
}

int sql_balance_inquiry(sqlite3 *db, u_node *unode)
{
    int ret;
    char *zErrMsg = 0;

    char sql[128] = {0};
    sprintf(sql, "select * from user where name=\"%s\" and phone=\"%s\";", unode->name, unode->phone);
    ret = sqlite3_exec(db, sql, findone, unode, &zErrMsg);
    if (ret != SQLITE_OK)
    {
        printf("[%d]sqlite3_exec:%s--%s\n", __LINE__, sqlite3_errmsg(db), zErrMsg);
        sqlite3_free(zErrMsg);
        return -1;
    }

    return 0;
}

int sql_login(sqlite3 *db, u_node *unode)
{
    int ret;
    char *zErrMsg = 0;

    char sql[128] = {0};
    sprintf(sql, "select * from user where name=\"%s\" and password=\"%s\";", unode->name, unode->password);
    ret = sqlite3_exec(db, sql, findone, unode, &zErrMsg);
    if (ret != SQLITE_OK)
    {
        printf("[%d]sqlite3_exec:%s--%s\n", __LINE__, sqlite3_errmsg(db), zErrMsg);
        sqlite3_free(zErrMsg);
        return -1;
    }

    unode->status = 1;
    sprintf(sql, "update user set status = '%hd' where id = '%s';", unode->status, unode->id);
    ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (ret != SQLITE_OK)
    {
        printf("[%d]sqlite3_exec:%s\n", __LINE__, sqlite3_errmsg(db));
        return -1;
    }

    return 0;
}

int sqlrepass(sqlite3 *db, u_node *unode)
{
    int ret;

    char sql[128] = {0};

    unode->status = 0;
    sprintf(sql, "update user set password='%s', status = '%hd' where name='%s' and phone='%s';",
            unode->password, unode->status, unode->name, unode->phone);
    fprintf(stderr, "[%d]%s\n", __LINE__, sql);
    ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (ret != SQLITE_OK)
    {
        printf("[%d]sqlite3_exec:%s\n", __LINE__, sqlite3_errmsg(db));
        return -1;
    }
    return 0;
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

void show_f_list(f_list flist)
{
    printf("num\tid\tflight_number\t Starting destin\t Address\t ftype boardingTime \tprice \tsurplusVote flags\n");
    f_list tmp, n;
    int i = 0;
    list_for_each_entry_safe(tmp, n, &flist->head, head)
    {
        printf("[%d]%s\t%s\t%s\t%s\t%s\t%c\t%s\t%u\t%u\t%u\n", ++i, tmp->id, tmp->flight_number, tmp->Starting,
               tmp->destin, tmp->Address, tmp->ftype, tmp->boardingTime, tmp->price, tmp->surplusVote, tmp->flags);

        list_del(&tmp->head);
        free(tmp);
    }
    printf("\n");
    return;
}

int sql_recharge(u_node *c, sqlite3 *db)
{
    int ret;
    char sql[128] = {0};

    sprintf(sql, "update user set account = '%d' where name = '%s' and phone = '%s' ;", c->account, c->name, c->phone);

    printf("[%d]%s\n", __LINE__, sql);

    ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (ret != SQLITE_OK)
    {
        printf("[%d]sqlite3_exec:%s\n", __LINE__, sqlite3_errmsg(db));
        return -1;
    }

    return 0;
}

int sql_update_account(u_node *c, sqlite3 *db)
{
    int ret;
    char sql[128] = {0};

    sprintf(sql, "update user set account = '%d' where id = '%s' ;", c->account, c->id);

    printf("[%d]%s\n", __LINE__, sql);

    ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (ret != SQLITE_OK)
    {
        printf("[%d]sqlite3_exec:%s\n", __LINE__, sqlite3_errmsg(db));
        return -1;
    }

    return 0;
}

int updata_user(u_node *c, sqlite3 *db)
{
    int ret;
    char sql[128] = {0};

    sprintf(sql, "update user set name = '%s', phone = '%s' where id = '%s';", c->name, c->phone, c->id);
    ret = sqlite3_exec(db, sql, NULL, NULL, NULL);
    if (ret != SQLITE_OK)
    {
        printf("[%d]sqlite3_exec:%s\n", __LINE__, sqlite3_errmsg(db));
        return -1;
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
        printf("[%d]sqlite3_exec:%s\n", __LINE__, sqlite3_errmsg(ppdb));
        return -1;
    }

    return 0;
}
