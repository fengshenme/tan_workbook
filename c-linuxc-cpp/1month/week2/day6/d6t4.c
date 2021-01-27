/**

1.构造一个结构体模板（图书信息），有下列成员：
序号	int
书名	char [20]
页数	int
价格	float

同时定义一个变量 stu1
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

void input_book(int len, struct book_info *stu1);

void show(int len ,struct book_info *stu1);

int main(int argc, char const *argv[])
{
    int a;
    struct book_info stu1[3] ;
    bzero(stu1,3*sizeof(struct book_info));
    int i = 0;
    while (1)
    {
        printf("录入书籍信息输入1,显示信息输入2,按0退出");
        scanf("%d", &a); while (getchar() != '\n');
        if (a == 1)
        {
            input_book(3,&stu1[i]);
            i++;
        }
        else if (a == 2)
        {
            show(3,stu1);
        }
        else if (a == 0)
            return 1;
        
    }

    return 0;
}

void show(int len, struct book_info *stu1)
{

    system("clear");
    printf("序号\t书名\t页数\t价格\n");
    for (size_t i = 0; i < len; i++)
        printf("%d\t%s\t%d\t%.3f\n", stu1[i].number, stu1[i].title, stu1[i].pages, stu1[i].price);
}

void input_book(int len, struct book_info *stu1)
{

    int i = 0;
    for ( i; i < len; i++)
        if (stu1[i].number == 0)
            break;

    if (i>=len)
    {   
        printf("full!!!\n");
        return;
    }
    
    stu1[i].number = i;
    

    // printf("书籍序号");
    // scanf("%d", stu1[1]->number);
    // while (getchar() != '\n')
        ;
    printf("书名");
    scanf("%s", stu1[i].title);
    while (getchar() != '\n')
        ;
    printf("页数");
    scanf("%d", &stu1[i].pages);
    while (getchar() != '\n')
        ;
    printf("价格");
    scanf("%f", &stu1[i].price);
    while (getchar() != '\n')
        ;
}