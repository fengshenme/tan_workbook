#include <stdio.h>
#include <string.h>

struct d6t3
{
    int num;
    char name[20];
    char info[100];
};

void show_info(struct d6t3 *a);

int main(int argc, char const *argv[])
{
    
    printf("============DATA=======================\n");
    printf("序号\t名字\t详情\n");
    struct d6t3 a1 = {1,"acc","nigeajo哈哈哈哈"};
    show_info(&a1);
    struct d6t3 a2;

    a2.num = 2 ;
    strncpy(a2.name, "sde",sizeof(a2.name));
    strncpy(a2.info, "优秀的人,哈哈哈哈哈!!!!",sizeof(a2.info));
   
    show_info(&a2);

    return 0;
}

void show_info(struct d6t3 *a)
{
    printf("%d\t",a->num);
    printf("%s\t",a->name);
    printf("%s\n",a->info);
}
