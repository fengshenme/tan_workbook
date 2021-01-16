#include <stdio.h>

struct book_info
{
    int number;
    char title[20];
    int pages;
    float price;
};

int main(int argc, char const *argv[])
{
    struct book_info book[20] = {
        {1, "test", 60, 13.14},
        {2, "main", 100, 66.5},
        {3, "what", 300, 60.5},
        {4, "first", 600, 200.5},
    };
    printf("序号\t书名\t页数\t价格\n");
    for (size_t i = 0; i < 20; i++)
    {    if (book[i].number == 0)
                break;
        printf("%d\t%s\t%d\t%.3f\n", book[i].number, book[i].title, book[i].pages, book[i].price);
    }
    int i,num ;
    scanf("%d", &num);
    
    for (i = num -1; i < 20; i++)
    {
        if (book[i].number == 0)
            break;
        book[i] = book[i+1];
        if(book[i].number > 0)
            book[i].number--;
    }
    printf("序号\t书名\t页数\t价格\n");
    for (size_t i = 0; i < 20; i++)
    {    if (book[i].number == 0)
                break;
        printf("%d\t%s\t%d\t%.3f\n", book[i].number, book[i].title, book[i].pages, book[i].price);
    }
    return 0;
}
