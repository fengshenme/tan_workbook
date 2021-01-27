#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
  FILE *fp = fopen("data/aa.txt", "w");

  unsigned char y, x, i;
  // 0x0A
  int count = 0;
  for (i = 0xe3; i < 0xfe; i++)
  {

    for (x = 0x80; x < 0xfe; x++)
    {
      for (y = 0x80; y < 0xfe; y++)
      {

        //   fprintf(fp, "%c", i);
        fprintf(fp, "%c", i);
        fprintf(fp, "%c", x);
        fprintf(fp, "%c", y);
        //   fprintf(fp, "%c", 0x0D); // windos 0x0D 0x0A unix 0x0A
        fprintf(fp, "%c", 0x0A);

        count += 1;
        if (count > 0x1b * 0x7e * 0x7e)
          break;
      }
    }
  }

  printf("%d\n", count);
  fclose(fp);
  return 0;
}
