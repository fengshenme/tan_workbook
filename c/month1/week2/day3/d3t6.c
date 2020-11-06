#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    // 题13
    int a[3][3], *p, i; //{1, 2, 3},{4,5,6},{7,8,9}}
    p = &a[0][0];
    for (i = 0; i < 9; i++)
        p[i] = i + 1;
    printf("%d\n", a[1][2]); // 6

    // 题14
    char s[] = "Yes\n/No", *ps = s;
    puts(ps + 4);
    *(ps + 4) = 0;
    puts(s);

    //题15
    char str[][20] = {"Hello", "Beijing"}, *pp = str[0];
    printf("%d\n", strlen(pp + 20));
    printf("%d\n", strlen(pp));
    printf("%s\n", str[0]);
    printf("%s\n", *&str[0]);
    printf("%s\n", pp);
    
    //题16
    char sa[]= "ABCD",*pb; 
    for(pb=sa+1;pb<sa+4;pb++) printf("16:%s\n",pb);

    
    return 0;
}
