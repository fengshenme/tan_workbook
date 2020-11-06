#include <stdio.h>
#include <sys/types.h> 
#include <dirent.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <dir>\n", argv[0]);
        exit(1);
    }
    
    DIR *mydir ;
    mydir = opendir(argv[1]);
    struct dirent * dir_info;
    while (1)
    {
        /* code */
        dir_info = readdir(mydir);
        if (dir_info == NULL)
            break;
        printf("文件名:%s \n", dir_info->d_name);
        
    }
    closedir(mydir);

    return 0;
}
