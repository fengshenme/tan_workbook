/**

1.构造一个结构体模板（图书信息），有下列成员：
序号	int
书名	char [20]
页数	int
价格	float

同时定义一个变量 book
可通过scanf循环输入不同的数字，执行不同的操作，如
1写入数据到该结构体变量中(可继续使用scanf输入)
2显示结构体变量所有信息

2.完善图书管理系统。
密码功能：
a.输入用户名、密码
b.用户名错误，提示无此用户
c.密码错误，提示密码错误
d.都正确，打印 XXXX，欢迎使用XXX系统。

图书信息管理功能：
（序号、书名、作者名、页数、价格、库存）
a.增：添加新的图书信息
b.删：删除某个图书信息（也可删除中间）
c.改：修改某个图书信息
d.查：查询某个图书信息
（尝试完成一些拓展功能：
3次错误结束程序、借书还书功能。
（注意！！！尽量封装好各种函数，便于调试）

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NAMELEN 20

struct book_info
{
    int number; // 序号
    char title[NAMELEN];    // 书名
    char author[NAMELEN]; // 作者名
    int pages;  // 页数
    float price; // 价格
    int stock; // 库存
};

struct book_user // 用来存放一个带有一定数据格式的用户
{
    char name[NAMELEN];
    char password[NAMELEN];
};

//添加书籍
void input_book(int len, struct book_info *book);

//查询全部书籍
void find_all(struct book_info *book);
//查询单本书籍
void find_one(int id, struct book_info *book);
//删除一本书
void del_one(int id, struct book_info *book);
//更新书籍信息
void update_one(int id, struct book_info *book);
// 首页信息
void book_index(struct book_info *book, struct book_user *use1);
//登录函数
bool book_login(struct book_user *use, FILE *fp);

#define COUNT 10

int main(int argc, char const *argv[])
{
    struct book_info book[COUNT] = {
        {1, "test","张三", 60, 13.14, 3},
        {2, "main","李四", 100, 66.5, 5},
        {3, "what","易中天", 300, 60.5, 6},
        {4, "first","莫言", 600, 200.5, 7},
    };
    struct book_user *use1 = malloc(sizeof(struct book_user));
    bool status = false;
    
    for (size_t i = 0; i < 3; i++)
    {
        FILE *fp = fopen("/mnt/sharecode/week3/day5/user_data.txt", "r");
        status = book_login(use1, fp);
        fclose(fp); // 关闭文件
        if(status)
            break;
    }
    if (status)
        book_index(book, use1);

    free(use1);
    
    return 0;
}
//显示所有书籍
void find_all(struct book_info *book)
{

    system("clear");
    printf("序号\t书名\t\t作者\t\t页数\t价格\t\t库存\n");
    for (size_t i = 0; i < COUNT; i++)
    {
        if (book[i].number == 0)
                continue;
        printf("%d\t%s\t\t%s\t\t%d\t%.3f\t\t%d\n", book[i].number, book[i].title, book[i].author, 
                                    book[i].pages, book[i].price, book[i].stock);
    }
        
}
// 添加新书籍
void input_book(int len, struct book_info *book)
{

    int i;
    for (i = 0; i < len; i++)
        if (book[i].number == 0)
            break;

    if (i == len)
    {
        printf("full!!!\n");
        return;
    }

    book[i].number = i + 1;
    printf("书名");
    scanf("%s", book[i].title);
    while (getchar() != '\n')
        ;
    printf("作者");
    scanf("%s", book[i].title);
    while (getchar() != '\n')
        ;
    printf("页数");
    scanf("%d", &book[i].pages);
    while (getchar() != '\n')
        ;
    printf("价格");
    scanf("%f", &book[i].price);
    while (getchar() != '\n')
        ;
    printf("库存");
    scanf("%d", &book[i].pages);
    while (getchar() != '\n')
        ;
}

//查询单本
void find_one(int id, struct book_info *book)
{
    int j = 0, i;
    for (i = 0; i < COUNT; i++)
    {
        if (book[i].number == id && id != 0)
        {
            j = i;
            printf("序号\t书名\t\t作者\t\t页数\t价格\t\t库存\n");
            printf("%d\t%s\t\t%s\t\t%d\t%.3f\t\t%d\n", book[i].number, book[i].title, book[i].author, 
                                    book[i].pages, book[i].price, book[i].stock);
        }
    }
    if (j == 0)
    {
        printf("书籍不存在或者序号输入错误\n");
    }
}

//删除一本书籍
void del_one(int id, struct book_info *book)
{
    for (size_t i = 0; i < COUNT; i++)
    {
        if (book[i].number == id)
        {
            bzero(&book[i], sizeof(struct book_info));
        }
    }
}

//更新书籍信息
void update_one(int id, struct book_info *book)
{

    int j = 0, i;
    for (i = 0; i < COUNT; i++)
    {
        if (book[i].number == id && id != 0)
        {
            j = id;
            printf("================请选择更新图书项==============\n"
                   "0)书名 \t 1)页数\t 2)价格 3)作者 4)库存\n"
                   "请选择:");
            int num; // 数字选项
            scanf("%d", &num);
            while (getchar() != '\n')
                ;
            switch (num)
            {
            case 0:
                printf("书名");
                scanf("%s", book[i].title);
                while (getchar() != '\n')
                    ;
                break;
            case 1:
                printf("页数");
                scanf("%d", &book[i].pages);
                while (getchar() != '\n')
                    ;
                break;
            case 2:
                printf("价格");
                scanf("%f", &book[i].price);
                while (getchar() != '\n')
                    ;
                break;
            case 3:
                printf("作者");
                scanf("%s", book[i].author);
                while (getchar() != '\n')
                    ;
                break;
            case 4:
                printf("库存");
                scanf("%d", &book[i].stock);
                while (getchar() != '\n')
                    ;
                break;
            default:
                break;
            }
        }
    }

    if (j == 0)
    {
        printf("书籍不存在或者序号输入错误\n");
    }
}

//首页信息
void book_index(struct book_info *book, struct book_user *use1)
{
    int num;    //数字选项
    while (1)
    {
        printf("================%s, 欢迎使用图书管理系统==============\n"
               "0)退出       \t 1)录入书籍\t 2)全部书籍查询\n"
               "3)单本书籍查询\t 4)书籍修改\t 5)书籍删除\n"
               "请选择:",use1->name);
        scanf("%d", &num);
        while (getchar() != '\n')
            ;
        int id = 0;
        switch (num)
        {
        case 0:
            return;
            break;
        case 1:
            input_book(COUNT, book);
            break;
        case 2:
            find_all(book);
            break;
        case 3:
        {
            printf("请输入查询书籍序号:");
            scanf("%d", &id);
            while (getchar() != '\n')
                ;
            find_one(id, book);
            break;
        }
        case 4:
            printf("请输入更新书籍序号:");
            scanf("%d", &id);
            while (getchar() != '\n')
                ;
            update_one(id, book);
            break;
        case 5:
            printf("请输入要删除书籍序号:");
            scanf("%d", &id);
            while (getchar() != '\n')
                ;
            del_one(id, book);
            break;
        default:
            printf("请输入正确数字!");
            break;
        }
    }
}

//登录函数
bool book_login(struct book_user *use, FILE *fp)
{
    printf("请登录\n用户名:");
    scanf("%s", use->name);while (getchar() != '\n');
    printf("密码:");
    scanf("%s", use->password); while (getchar() != '\n');

    while (1)
    {
        struct book_user *_user = malloc(sizeof(struct book_user));
        //从文件fp中按照格式读取数据
        if (fscanf(fp, "%s %s", _user->name, _user->password) == EOF)
            break;
        if (strcmp(_user->name, use->name) == 0)
        {
            if (strcmp(_user->password, use->password) == 0)
            {
                return true;
            }
            else
            {
            printf("密码错误\n"); 
            return false;
            }
        }
        free(_user);
    }
    printf("无此用户\n");
    return false;
    
}
