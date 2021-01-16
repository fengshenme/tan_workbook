#include "copy_file.h"

void *p_copy_file(void *arg)
{

    plural_path *pd_path = (plural_path *)arg; //malloc(sizeof(plural_path));

    // memset(pd_path, 0, sizeof(plural_path));
    // memcpy(pd_path, arg, sizeof(plural_path));

    char *src_path = pd_path->s_path;
    char *des_path = pd_path->d_path;

    // printf("70 %s \n", src_path);
    // printf("71 %s \n", des_path);

    // 检测源文件是否存在, 源文件的属性读取出来
    struct stat fileinfo;
    if (stat(src_path, &fileinfo) == -1)
    {
        fprintf(stderr, "[%d]: get file info failed\n", __LINE__);
    }
    //获取文件权限
    unsigned int perm = fileinfo.st_mode & 0777;

    if (access(des_path, F_OK) == 0) //检测目标文件是否存在
    {
        struct stat dirfile_info;
        if (stat(des_path, &dirfile_info) == -1)
        {
            fprintf(stderr, "get file info failed\n");
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

            // 源目录与目标目录检测
            if (strncmp(src_path, des_path, strlen(src_path)))
            {
                fprintf(stderr, "The parent directory cannot be copied to the child directory! \n");
                exit(1);
            }

            dirtodir(src_path, des_path, perm); // des_path目录就复制出来了,现在需要把src_path下的内容复制到新的des_path目录下

            DIR *dir = opendir(src_path);
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

                plural_path *pc_path = malloc(sizeof(plural_path));
                memset(pc_path, 0, sizeof(plural_path));

                strcpy(pc_path->d_path, tmp_d);
                strcpy(pc_path->s_path, tmp_p);
                pc_path->pool = pd_path->pool;

                printf("135 %s\n", pc_path->s_path);
                printf("136 %s\n", pc_path->d_path);
                add_thread(pc_path->pool, 1);
                if (add_task(pd_path->pool, p_copy_file, (void *)pc_path))
                {
                    printf("155 %d\n", dir_info->d_type);
                    printf("asd----\n");
                }
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

    free(pd_path);

    return NULL;
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
    printf("400 %s\n", src_path);
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
