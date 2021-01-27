/**
 * 
 * 
指出以下代码第二次输出结果，解释原因。 
 * 
*/
// # 通过函数修改指针
void other(void);
int main(void)
{
    extern int a;
    int b = 0;
    static int c;
    a += 3;
    func(); // a 8| a 13 b 8 c 7 //  c=8 a 13
    b += 3;
    func(); // a 18 b 8 c 13 | 18 8 13
}
int a = 5;
void func(void)
{
    int b = 3;
    static int c = 2;
    a += 5; //
    b += 5; 
    c += 5;
    printf("%d, %d, %d\n", a, b, c);
    c = b;
}