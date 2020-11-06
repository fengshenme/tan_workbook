#include <stdio.h>


int main(int argc, char const *argv[])
{
    int arr[8] = {[0 ... 4]=666, [5 ... 7]=999};

    for (size_t i = 0; i < 8; i++)
    {
        /* code */
        printf("%d ", arr[i]);
    }
    arr[7] += 1;
    printf("\n====================\n");
    for (size_t i = 0; i < 8; i++)
    {
        /* code */
        printf("%d ", arr[i]);
    }

    return 0;
}
