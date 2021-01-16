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

    char src_path[256];
    char des_path[256];

    // 读取输入文件字符串路径
    strncpy(src_path, argv[1], strlen(argv[1]));
    strncpy(des_path, argv[2], strlen(argv[2]));

    thread_pool *pool = malloc(sizeof(thread_pool));
    init_pool(pool, 2); //2个线程都在条件变量中睡眠

    trans_dir(src_path);
    trans_dir(des_path);

    copy2(src_path, des_path, pool);
    // copy(src_path, des_path);
    destroy_pool(pool);
    // free(p_path);

    return 0;
}
