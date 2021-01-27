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

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book_info
{
    int number;
    char title[20];
    int pages;
    float price;
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

#define COUNT 10

int main(int argc, char const *argv[])
{
    int a;
    struct book_info book[COUNT] = {
        {1, "test", 60, 13.14},
        {2, "main", 100, 66.5},
        {3, "what", 300, 60.5},
        {4, "first", 600, 200.5},
    };
    // bzero(book,5*sizeof(struct book_info));
    while (1)
    {
        printf("================图书管理系统==============\n"
               "0)退出       \t 1)录入书籍\t 2)全部书籍查询\n"
               "3)单本书籍查询\t 4)书籍修改\t 5)书籍删除\n"
               "请选择:");
        scanf("%d", &a);
        while (getchar() != '\n')
            ;
        int id = 0;
        switch (a)
        {
        case 0:
            return 1;
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

    return 0;
}
//显示所有书籍
void find_all(struct book_info *book)
{

    system("clear");
    printf("序号\t书名\t页数\t价格\n");
    for (size_t i = 0; i < COUNT; i++)
        printf("%d\t%s\t%d\t%.3f\n", book[i].number, book[i].title, book[i].pages, book[i].price);
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
    printf("页数");
    scanf("%d", &book[i].pages);
    while (getchar() != '\n')
        ;
    printf("价格");
    scanf("%f", &book[i].price);
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
            printf("序号\t书名\t页数\t价格\n");
            printf("%d\t%s\t%d\t%.3f\n", book[i].number, book[i].title, book[i].pages, book[i].price);
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
                   "0)书名 \t 1)页数\t 2)价格\n"
                   "请选择:");
            int a;
            scanf("%d", &a);
            while (getchar() != '\n')
                ;
            switch (a)
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