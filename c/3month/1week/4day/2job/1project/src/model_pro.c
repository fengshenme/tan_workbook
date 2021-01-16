/**
 * @file model_pro.c
 * @author tan wei feng (1015956962@163.com)
 * @brief 逻辑层,模型相关
 * @version 0.1
 * @date 2020-10-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../include/main.h"

/**
 * @brief 获取file数据存入链表中,将文件路径存入数组中
 * 
 * @param pic_list 将存储文件绝对路径的数组
 * @param path_ac 目录绝对路劲
 * @return int -1:失败 
 */
int get_img(char (*pic_list)[256], char *path_ac)
{
    if (pic_list == NULL)
    {
        printf("pic_list calloc  failed!\n");
        return -1;
    }

    

    // int pic_size = find_file(path_ac, head_global, ".ebm");
    int pic_size = find_file(path_ac, head_global, ".jpeg");
    printf("%d -a-\n", pic_size);
    refresh_data(pic_list);
    return pic_size;
}

//刷新数据
int refresh_data(char (*pic_list)[256])
{
    bzero(pic_list, 20 * 256);
    struct list_head *pos;
    int i = 0;
    list_for_each(pos, &head_global->list)
    {
        kl_pt get_node = list_entry(pos, kl_img, list);

        strcpy(pic_list[i], get_node->path);

        i++;
        printf("%s\t", get_node->path);
        printf("%s\t", get_node->name);
        printf("%d\t", get_node->size);
        printf("%s\n", asctime(gmtime(&get_node->c_time)));
    }
    return 0;
}

/**
 * 查找目录下文件ebm
 * @param name 查找目录名
 * @param f_suffix 文件后缀名
 */
int find_file(const char *name, kl_pt head, char *f_suffix)
{
    DIR *mydir;
    mydir = opendir(name);
    struct dirent *dir_info;
    int i_count = 0;
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

            kl_pt n_img = malloc(sizeof(kl_img));
            if (n_img == NULL)
            {
                printf("img_node malloc fialed!!\n");
                return -1;
            }

            strcpy(n_img->path, path_o);

            struct stat file_info;
            stat(n_img->path, &file_info);
            n_img->name = f_name;
            n_img->size = file_info.st_size;
            n_img->c_time = file_info.st_ctime;
            kl_img_add(n_img, head);

            i_count++;
        }
        if (isdir(path_o))
        {
            i_count += find_file(path_o, head, f_suffix);
        }
        free(path_o);
    }

    closedir(mydir);
    return i_count;
}

/**
 * @brief 输入目录处理
 * 
 * @param i_path 
 * @param des_path 
 * @return 0:成功 1:失败
 */
int dir_proc(const char *i_path, char *des_path)
{
    if (des_path == NULL)
    {
        printf("des_path malloc  failed!\n");
        return 1;
    }
    bzero(des_path, 256);

    if (!isdir(i_path)) // 判断输入参数是否为目录
    {
        printf("Not a directory\n");
        exit(1);
    }

    char *last_str;
    const char *str_tmp;
    if (*(strrchr(i_path, '\0') - 1) == '/')
    {
        *(strrchr(i_path, '/')) = '\0';
    }
    last_str = strrchr(i_path, '/');
    str_tmp = last_str == 0 ? i_path : last_str + 1;

    getcwd(des_path, 256);
    strcat(des_path, "/");
    strcat(des_path, str_tmp);
    return 0;
}

kl_pt kl_init()
{
    kl_pt n_img = malloc(sizeof(kl_img));
    if (n_img == NULL)
    {
        printf("img_node malloc fialed!!\n");
        return NULL;
    }

    n_img->list.next = &n_img->list;
    n_img->list.prev = &n_img->list;
    return n_img;
}

int kl_img_add(kl_pt n_img, kl_pt head)
{

    list_add(&n_img->list, &head->list);

    return 0;
}

//排序
void kl_sort(kl_pt head, int select)
{
    kl_pt pos, get_bign;
    struct list_head *lh;

    list_for_each_entry(pos, &head->list, list)
    {
        list_for_each_prev(lh, &head->list)
        {
            get_bign = list_entry(lh, kl_img, list);
            switch (select)
            {
            case 1: //根据文件名首字母排序
            {
                if((get_bign->name)[1] < (pos->name)[1])
                {
                    list_move(lh, &pos->list);
                }
                break;
            }
            case 2: //根据文件大小排序
            {
                if (get_bign->size < pos->size)
                {
                    list_move(lh, &pos->list);
                }
                break;
            }
            default: //根据时间排序
            {
                if (get_bign->c_time < pos->c_time)
                {
                    list_move(lh, &pos->list);
                }
                break;
            }
            }
        }
    }
}