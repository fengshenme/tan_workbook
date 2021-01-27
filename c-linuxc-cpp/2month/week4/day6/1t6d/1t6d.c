#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>

/**
 * @brief 主函数
 * 
 * @param argc 输入参数个数
 * @param argv 输入参数组成的字符串数组
 * @return int 
 */

/**
 * @brief 文件复制
 * 
 * @param src_path 源文件绝对路径
 * @param des_path 目标文件绝对路径
 * @param perm 文件权限 8进制
 * @return int 
 */
int filetofile(char *src_path, char *des_path, unsigned int perm);

/**
 * @brief 文件复制到目录下
 * 
 * @param src_path 
 * @param des_path 
 * @param perm 文件权限 8进制
 * @return int 
 */
int filetodir(char *src_path, char *des_path, unsigned int perm);


/**
 * @brief 目录复制到目录下
 * 
 * @param src_path 
 * @param des_path 
 * @param perm 
 * @return int 
 */
int dirtodir(char *src_path, char *des_path, unsigned int perm);

/**
 * @brief 复制 
 * 
 * @param src_path 
 * @param des_path 
 * @return int 
 */
int copy(char *src_path, char *des_path);

/**
 * @brief 将输入路径转换为绝对路径
 * 
 * @param src_path 
 * @return int 
 */
int trans_dir(char *src_path);

int main(int argc, char const *argv[])
{

    if (argc != 3)
    {
        fprintf(stderr, "Uage: %s <src> <dst> \n", argv[0]);
        exit(1);
    }

    // 读取输入文件字符串路径
    char src_path[256], des_path[256];
    // 内存清零
    memset(src_path, 0, (size_t)256);
    memset(des_path, 0, (size_t)256);

    strncpy(src_path, argv[1], strlen(argv[1]));
    strncpy(des_path, argv[2], strlen(argv[2]));

    copy(src_path, des_path);

    return 0;
}

int trans_dir(char *src_path)
{
    char *path = malloc(200);
    memset(path, 0, 200);
    getcwd(path, 256);
    if (src_path[0] != '/')
    {

        if (src_path[0] == '.' && src_path[1] == '.' && src_path[2] == '/')
        {
            char *delim = "/";
            char(*dir_name)[30] = malloc(30 * 30);
            char *p = strtok(src_path, delim);
            int i = 1;
            strcpy(dir_name[0], p);
            while ((p = strtok(NULL, delim)))
            {
                strcpy(dir_name[i], p);
                i++;
            }
            i--;
            int t = i;
            while (i > 0)
            {
                char *c_site = strrchr(path, '/');
                memset(c_site, 0, strlen(c_site));

                i--;
            }
            strcat(path, "/");
            strcat(path, dir_name[t]);
            free(dir_name);
        }
        else
        {
            if (src_path[1] == '/')
            {
                strcat(path, &src_path[1]);
            }
            else
            {
                strcat(path, "/");
                strcat(path, src_path);
            }
        }

        memset(src_path, 0, strlen(src_path));
        strncpy(src_path, path, strlen(path));
    }

    free(path);
    return 1;
}

int copy(char *src_path, char *des_path)
{
    trans_dir(src_path);
    trans_dir(des_path);

    // printf("109 %s \n", src_path);
    // printf("110 %s \n", des_path);

    // 检测源文件是否存在, 源文件的属性读取出来
    struct stat fileinfo;
    if (stat(src_path, &fileinfo) == -1)
    {
        printf("get file info failed\n");
        return -1;
    }
    //获取文件权限
    unsigned int perm = fileinfo.st_mode & 0777;

    if (access(des_path, F_OK) == 0) //检测目标文件是否存在
    {
        struct stat dirfile_info;
        if (stat(des_path, &dirfile_info) == -1)
        {
            printf("get file info failed\n");
            return -1;
        }

        // 普通文件拷贝
        if ((fileinfo.st_mode & S_IFMT) == S_IFREG)
        {
            if ((dirfile_info.st_mode & S_IFMT) == S_IFREG)
            {
                filetofile(src_path, des_path, perm);
            }
            else if ((dirfile_info.st_mode & S_IFMT) == S_IFDIR)
            {
                filetodir(src_path, des_path, perm);
            }
        }
        else if ((fileinfo.st_mode & S_IFMT) == S_IFDIR && (dirfile_info.st_mode & S_IFMT) == S_IFDIR)
        {
            DIR *dir = opendir(src_path);
            dirtodir(src_path, des_path, perm); // des_path目录就复制出来了,现在需要把src_path下的内容复制到新的des_path目录下

            char *tmp_p = malloc(256);
            char *tmp_d = malloc(256);

            struct dirent *dir_info;
            while ((dir_info = readdir(dir)) != NULL)
            {
                if (strcmp(dir_info->d_name, ".") == 0 || strcmp(dir_info->d_name, "..") == 0)
                    continue;
                memset(tmp_p, 0, 256);
                memset(tmp_d, 0, 256);

                strncpy(tmp_p, src_path, 256); //克隆一份数据去运算
                strncpy(tmp_d, des_path, 256);

                strcat(tmp_p, "/"); 
                strcat(tmp_p, dir_info->d_name);

                copy(tmp_p, tmp_d); // 递归复制

                printf("161 %d\n", dir_info->d_type);
            
            }
            free(tmp_p);
            free(tmp_d);
            closedir(dir);
        }
    }
    else if ((fileinfo.st_mode & S_IFMT) == S_IFREG)
    {
        // 普通文件拷贝
        filetofile(src_path, des_path, perm);
    }

    return 0;
}

int dirtodir(char *src_path, char *des_path, unsigned int perm)
{
    char *delim = "/";
    char(*dir_name)[30] = malloc(30 * 30);
    char *path = malloc(256);
    strcpy(path, src_path);

    char *p = strtok(path, delim);
    int i = 1;
    strcpy(dir_name[0], p);
    while ((p = strtok(NULL, delim)))
    {
        strcpy(dir_name[i], p);
        i++;
    }

    strcat(des_path, "/");
    strcat(des_path, dir_name[i - 1]);

    mkdir(des_path, (mode_t)perm);

    free(dir_name);
    free(path);

    return 0;
}

int filetodir(char *src_path, char *des_path, unsigned int perm)
{

    char *delim = "/";
    char(*dir_name)[30] = malloc(30 * 30);
    char *path = malloc(256);
    strcpy(path, src_path);

    char *p = strtok(path, delim);
    int i = 1;
    strcpy(dir_name[0], p);
    while ((p = strtok(NULL, delim)))
    {
        strcpy(dir_name[i], p);
        i++;
    }

    strcat(des_path, "/");
    strcat(des_path, dir_name[i - 1]);
    printf("%s\n", src_path);
    filetofile(src_path, des_path, perm);

    free(dir_name);
    return 0;
}

int filetofile(char *src_path, char *des_path, unsigned int perm)
{

    int fr, fw;

    char *buf = malloc(1024);
    memset(buf, 0, 1024);

    printf("is file \n");
    fr = open(src_path, O_RDONLY, perm);
    fw = open(des_path, O_WRONLY | O_CREAT | O_TRUNC, perm); //没有就创建,有就清空在写入
    if (fr == -1)
    {
        fprintf(stderr, "file open failed \n");
    }
    while (1)
    {
        int ret = read(fr, buf, 1024);

        if (ret <= 0)
            break;

        write(fw, buf, ret);
    }

    free(buf);
    close(fr);
    close(fw);

    return 0;
}
