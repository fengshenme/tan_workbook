#include <sqlite3.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 打开数据库 不存在则创建,
 * 
 * @param ppDb 
 * @return int 
 */
int openDb(sqlite3 **ppDb);

/**
 * @brief 创建一个数据库表
 * 
 * @param ppDb 数据库句柄
 * @return int 
 */
int createTable(sqlite3 *ppDb);
/**
 * @brief 添加书本
 * 
 * @param ppDb 
 * @return int 
 */
int addBook(sqlite3 *ppDb);

/**
 * @brief 删除书本
 * 
 * @param ppDb 
 * @return int 
 */
int deleteData(sqlite3 *ppDb);

/**
 * @brief 更新书本
 * 
 * @param ppDb 
 * @return int 
 */
int updateBook(sqlite3 *ppDb);

/**
 * @brief 查询书本
 * 
 * @param ppDb 
 * @return int 
 */
int selectBook(sqlite3 *ppDb);

/**
 * @brief 查询功能的回调函数
 * 
 * @param NotUsed用户传入指针
 * @param argc 字段数
 * @param argv 元祖
 * @param azColName  字段名字符串数组
 * @return int 
 */
int callback(void *NotUsed, int argc, char **argv, char **azColName);

/**
 * @brief 删除指定字符
 * 
 * @param str 
 * @param del 
 * @return int 
 */
int strrep(char *str, char del);

int main(int argc, char const *argv[])
{
    sqlite3 *ppDb = NULL;

    openDb(&ppDb);
    createTable(ppDb);

    //C语言的经典套路--》switch-case做功能选择
    char n;
    while (1)
    {
        //装模作样打印一个菜单让用户选择
        printf("1:插入图书信息\n");
        printf("2:删除图书信息\n");
        printf("3:修改图书信息\n");
        printf("4:查询图书信息\n");
        scanf("%c", &n); while (getchar() != '\n');

        switch (n)
        {
        case '1':
            //插入图书信息
            addBook(ppDb);
            break;
        case '2':
            //删除图书信息
            deleteData(ppDb);
            break;
        case '3':
            //修改图书信息
            updateBook(ppDb);
            break;
        case '4':
            //查询图书信息
            selectBook(ppDb);
            break;
        }

    }

    sqlite3_close(ppDb);

    return 0;
}

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int selectBook(sqlite3 *ppDb)
{

    char bookname[20];
    printf("请输入书籍名字(不输入默认全部):");
    scanf("%s", bookname); while (getchar() != '\n');
    strrep(bookname, '\n');

    //字符串拼接得到完整的插入语句
    char cmd[128];
    if (strlen(bookname) == 0)
        sprintf(cmd, "select * from tb_book;");
    else
    {
        sprintf(cmd, "select * from tb_book where title='%s';", bookname);
    }

    char *errmsg;
    int ret = sqlite3_exec(ppDb, cmd, callback, NULL, &errmsg);

    if (ret != SQLITE_OK)
    {
        printf("[%d]sql exec error msg: %s \n", __LINE__, errmsg);
    }
    return 0;
}

int updateBook(sqlite3 *ppDb)
{
    char bookname[20];
    float price;
    printf("请输入要调整售价的书籍名字:");
    scanf("%s", bookname); while (getchar() != '\n');
    printf("要调整的价格:");
    scanf("%f", price); while (getchar() != '\n');

    char cmd[128] = {0};
    sprintf(cmd, "update tb_book set price=%f  where title='%s';", price, bookname);
    strrep(cmd, '\n');

    char *errmsg;
    int ret = sqlite3_exec(ppDb, cmd, NULL, NULL, &errmsg);

    if (ret != SQLITE_OK)
    {
        printf("[%d]sql exec error msg: %s \n", __LINE__, errmsg);
    }
    return 0;
}

int deleteData(sqlite3 *ppDb)
{
    if (ppDb == NULL)
    {
        printf("[%d]sql exec error msg: %s \n", __LINE__, "null");
    }

    char bookname[20];
    printf("请输入要删除的书籍名字:");
    fgets(bookname, sizeof(bookname), stdin);
    strrep(bookname, '\n');
    char cmd[128] = {0};
    sprintf(cmd, "delete from tb_book where title='%s';", bookname);

    char *errmsg;
    int ret = sqlite3_exec(ppDb, cmd, NULL, NULL, &errmsg);

    if (ret != SQLITE_OK)
    {
        printf("[%d]sql exec error msg: %s \n", __LINE__, errmsg);
    }
    return 0;
}

int openDb(sqlite3 **ppDb)
{
    int ret = sqlite3_open("test.db", ppDb);
    if (ret != SQLITE_OK)
    {
        printf("open db failed!, %d \n", ret);
    }
    return 0;
}

int createTable(sqlite3 *ppDb)
{
    char *errmsg;
    int ret = sqlite3_exec(ppDb, "create table if not exists tb_book(id char(5) primary key not null,title text not null, author text, price float);", NULL, NULL, &errmsg);

    if (ret != SQLITE_OK)
    {
        printf("[%d]sql exec error msg: %s \n", __LINE__, errmsg);
    }
    return 0;
}

int addBook(sqlite3 *ppDb)
{

    char bookname[20];
    char author[20];
    float price;
    printf("请输入书籍名字:");
    scanf("%s", bookname); while (getchar() != '\n');
    
    printf("请输入书籍作者:");
    scanf("%s", author); while (getchar() != '\n');
    
    printf("请输入书籍价格:");
    scanf("%f", &price); while (getchar() != '\n');

    int id = time(0) % 100000;
    //字符串拼接得到完整的插入语句
    char cmd[128];
    sprintf(cmd, "insert into tb_book values(%d, \"%s\", \"%s\", %f);", id, bookname, author, price);
    strrep(cmd, '\n');
    char *errmsg;
    int ret = sqlite3_exec(ppDb, cmd, NULL, NULL, &errmsg);

    if (ret != SQLITE_OK)
    {
        printf("[%d]sql exec error msg: %s \n", __LINE__, errmsg);
    }
    return 0;
}

int strrep(char *str, char del) // 删除指定字符
{
    int i, j, k = strlen(str);
    for (i = 0; i < k; i++)
    {
        if (str[i] == del)
        {
            for (j = i; j < k; j++)
            {
                str[j] = str[j + 1];
            }
            i--;
            k--;
        }
    }
    return 0;
}
