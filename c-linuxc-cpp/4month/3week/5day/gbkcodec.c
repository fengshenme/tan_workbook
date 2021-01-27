#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
  FILE *fp = fopen("data/aa.txt", "w");

  unsigned char y, x;
  // 0x0A
  int count = 0;
    for (x = 0xa1; x < 0xf9; x++)
    {
      for (y = 0xa1; y < 0xfe; y++)
      {

        fprintf(fp, "%c", y);
        fprintf(fp, "%c", x);
         // 换行windos 0x0D 0x0A unix 0x0A
        fprintf(fp, "%c", 0x0A);

        count += 1;
        if (count > 0x1b * 0x7e * 0x7e)
          break;
      }
  }

  printf("%d\n", count);
  fclose(fp);
  return 0;
}
