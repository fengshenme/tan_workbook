#include "copy_file.h"

/**
 * @brief 主函数
 * 
 * @param argc 输入参数个数
 * @param argv 输入参数组成的字符串数组
 * @return int 
 */

int main(int argc, char const *argv[])
{

    if (argc != 3)
    {
        fprintf(stderr, "Uage: %s <src> <dst> \n", argv[0]);
        exit(1);
    }


    thread_pool *pool = malloc(sizeof(thread_pool));
    init_pool(pool, 2); //2个线程都在条件变量中睡眠

    plural_path (*p_path) = malloc(sizeof(plural_path));
    memset(p_path, 0, sizeof(plural_path));


    strcpy(p_path->s_path, argv[1]);
    strcpy(p_path->d_path, argv[2]);
    p_path->pool = pool;

    trans_dir(p_path->s_path);
    trans_dir(p_path->d_path);


    if (!add_task(pool, p_copy_file, (void *)p_path))
    {
        printf("copy file failed \n");
    }

    destroy_pool(pool);
    free(p_path);

    return 0;
}
