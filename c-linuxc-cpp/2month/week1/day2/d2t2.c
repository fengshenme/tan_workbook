#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#include <sys/mman.h>
#include <linux/input.h>
#include <sys/stat.h>
#include <sys/types.h>

// *全局变量
unsigned int i_count = 0; //找到的数量

/**
 * 判断是否为目录
 * @param pathname 目录名
 * @return bool 
 * */
bool isdir(const char *pathname)
{
    struct stat file_info;
    int status = stat(pathname, &file_info);
    if (status == 0)
    {
        if (S_ISDIR(file_info.st_mode))
            return true;
    }
    return false;
}

// 输入目录处理
void dir_proc(const char * i_path, char * des_path)
{
    if (!isdir(i_path)) // 判断输入参数是否为目录
    {
        printf("Not a directory\n");
        exit(1);
    }
    
    char *last_str;
    const char *str_tmp;
    if(*(strrchr(i_path, '\0')-1) == '/')
    {
        *(strrchr(i_path, '/')) = '\0';
    }
    last_str = strrchr(i_path, '/');
    str_tmp = last_str == 0 ? i_path : last_str +1;
     
    getcwd(des_path, 256);
    strcat(des_path, "/");
    strcat(des_path, str_tmp);
    printf("ac-%s\n", des_path);
}

/**
 * 查找目录下文件ebm
 * @param name 查找目录名
 * @param f_suffix 文件后缀名
 */
void find_file(const char *name, char (*pic_list)[256], char *f_suffix)
{

    DIR *mydir;
    mydir = opendir(name);
    struct dirent *dir_info;

    while (1)
    {
        dir_info = readdir(mydir);
        if (dir_info == NULL)
            break;
        char *f_name;
        f_name = dir_info->d_name;

        //非0即真,字符串比较相同返回0
        if (!strcmp(f_name, ".") || !strcmp(f_name, ".."))
            continue;
        
        char *path_o = malloc(256);

        sprintf(path_o, "%s/%s", name, f_name);
        int len = strlen(f_name);
        if (!strcmp(f_name + len - strlen(f_suffix), f_suffix))
        {
            strcpy(pic_list[i_count], path_o);
            i_count++;
        }
        if (isdir(path_o))
        {
            find_file(path_o, pic_list, f_suffix);
        }
        free(path_o);
    }

    closedir(mydir);
    return;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <dir>\n", argv[0]);
        exit(1);
    }
    
    char (*pic_list)[256] = calloc(20, 256);
    if (pic_list == NULL)
    {
        perror("calloc failed");
        return 1;
    }
    bzero(pic_list, 20 * 256);
    
    char * path_ac = malloc(256);
    bzero(path_ac, 256);

    dir_proc(argv[1], path_ac);
    find_file(path_ac, pic_list, ".txt");

    for (size_t i = 0; i < i_count; i++)
    {
        printf("all:%s\n", pic_list[i]);
    }

    free(path_ac);
    free(pic_list);

    return 0;
}
