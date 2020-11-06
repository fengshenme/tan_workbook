#include <stdio.h>
#include <string.h>

/**
 * 6、编写一个程序，去掉给定字符串中重复的字符。例如给定”google”，输出”gole”。（华为笔试题）
 * 
*/
int main(int argc, char const *argv[])
{
    char s[20];
    scanf("%s", &s);
    while (getchar() != '\n');
    int i,j,k=strlen(s);
    printf("%d \n",k);
    for ( i = 0; i < k; i++)
    {
        for ( j = i+1; j < k; j++)
        {
            if(s[i] == s[j] )
            {
                int tmp;
				for(tmp=j;tmp<k;tmp++)//数组移动，让下一个字符覆盖当前的重复字符
					s[tmp] = s[tmp+1];
				j--;	//之后要让下一次重新判断当前的新字符是否还是重复的
				k--;	//由于删除了一个重复的字符，导致字符串长度减少一个

            }
                
        }
    }
    
    
    printf("%s\n",s);
    return 0;
}
