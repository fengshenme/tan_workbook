
int func(int a, int b);

extern int func_3(void);

// 返回其中最大值
int func_1(int a, int b)
{
    func_3();
    return a > b ? a : b;
}