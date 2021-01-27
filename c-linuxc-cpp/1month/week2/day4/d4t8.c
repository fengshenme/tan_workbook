#include <stdio.h>

int strlength(char *a)
{
    int i = 0;
    while (1)
    {
        if (*(a+i) == '\0')
            break;
        i++;
    }
    return i;
}

void strip(char str[])
{
    int i,j,k=strlength(str);
    for ( i = 0; i < k; i++)
    {
        if (str[i] == 32)
        {
            for ( j = i; j <k ; j++)
            {
                str[j]=str[j+1];
            }
            i--;
            k--;
        }
        
    }
    printf("%s\n", str);
}

/**
 * 7、编写一个程序，清除用户输入字符串中的空格符并将之输出。（例如用户输入”a b”，输出”ab”）
*/
int main(int argc, char const *argv[])
{
    char str[800];
    char a;
    int b=0;
    while (1)
    {
        scanf("%c", &a); 
        if(a == '\n') break;
        str[b]=a;
        b++;
    }
    str[b]='\0';
    strip(str);
    // int i,j,k=strlength(str);
    // for ( i = 0; i < k; i++)
    // {
    //     if (str[i] == 32)
    //     {
    //         for ( j = i; j <k ; j++)
    //         {
    //             str[j]=str[j+1];
    //         }
    //         i--;
    //         k--;
    //     }
        
    // }
    // printf("%s\n", str);
    
    return 0;
}
