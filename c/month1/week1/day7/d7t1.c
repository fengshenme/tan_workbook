#include <stdio.h>

int main(int argc, char const *argv[])
{
    unsigned char a = 0x3A;
    unsigned char b = 0xE1;

    // 0011 1010  a    1110 0001 b
//     位运算
// 0001	0x1
// 0010	0x2
// 0100	0x4
// 1000	0x8

// 1010 = 8 + 2 = 10

// 		高4位 低4位
// 位序		7654 3210
// 2进制	0011 1010
// 16进制	0x3A
    // a|b; 1111 1011 fb
    // a^b; 1101 1011 db
    // a>>1; 0001 1101 1d
    // b<<4; 0001 0000 10

    printf("0x%hhX\n", a|b);
    printf("0x%hhX\n", a^b);
    printf("0x%hhX\n", a>>1);
    printf("0x%hhX\n", b<<4);
    // 1010 0010    1000 0010     0010 0000
    unsigned short c = 0xA2;  // 2字节 = 16位
    unsigned short d = 0x20;
    // unsigned short e = 0x82;
    unsigned short e = c^d;
     
    printf("0x%hhx\n", e );


    return 0;
}
