/*
读取文件
下面是从文件读取单个字符的最简单的函数：
int fgetc( FILE * fp );
fgetc() 函数从 fp 所指向的输入文件中读取一个字符。返回值是读取的字符，如果发生错误则返回 EOF。下面的函数允许您从流中读取一个字符串：
char *fgets( char *buf, int n, FILE *fp );
函数 fgets() 从 fp 所指向的输入流中读取 n - 1 个字符。它会把读取的字符串复制到缓冲区 buf，并在最后追加一个 null 字符来终止字符串。
如果这个函数在读取最后一个字符之前就遇到一个换行符 '\n' 或文件的末尾 EOF，则只会返回读取到的字符，包括换行符。
您也可以使用 int fscanf(FILE *fp, const char *format, ...) 函数来从文件中读取字符串，但是在遇到第一个空格和换行符时，它会停止读取。

*/
#include <stdio.h> 
void main() {
   FILE *fp = NULL;
   char buff[255];
   fp = fopen("h:/test.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1: %s\n", buff );
   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );
   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   fclose(fp);
}
/*
首先，fscanf() 方法只读取了 This，因为它在后边遇到了一个空格。
其次，调用 fgets() 读取剩余的部分，直到行尾。最后，调用 fgets() 完整地读取第二行。
二进制 I/O 函数
下面两个函数用于二进制输入和输出：
size_t fread(void *ptr, size_t size_of_elements, 
             size_t number_of_elements, FILE *a_file);            
size_t fwrite(const void *ptr, size_t size_of_elements, 
             size_t number_of_elements, FILE *a_file);
这两个函数都是用于存储块的读写 - 通常是数组或结构体。
*/