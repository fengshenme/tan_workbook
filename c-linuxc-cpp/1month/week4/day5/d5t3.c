#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>



int main(int argc, char const *argv[])
{
    struct stat file_info;
    stat("/home/gec/b.txt", &file_info);
    /*
    struct stat { dev_t st_dev; // 普通文件所在存储器的设备号 
    mode_t st_mode; // 文件类型、文件权限 
    ino_t st_ino; // 文件索引号 
    nlink_t st_nlink; // 引用计数 
    uid_t st_uid; // 文件所有者的 
    UID gid_t st_gid; // 文件所属组的 
    GID dev_t st_rdev; // 特殊文件的设备号 
    off_t st_size; // 文件大小 
    blkcnt_t st_blocks; // 文件所占数据块数目 
    time_t st_atime; // 最近访问时间 
    time_t st_mtime; // 最近修改时间 
    time_t st_ctime; // 最近属性更改时间 
    blksize_t st_blksize; // 写数据块建议值 };
    */
    printf("普通文件所在存储器的设备号:%ld\n", file_info.st_dev);
    printf("文件类型、文件权限 :%d\n", file_info.st_mode);
    printf("文件索引号 :%d\n", file_info.st_ino);
    printf("引用计数:%d\n", file_info.st_nlink);
    printf("文件所有者的:%d\n", file_info.st_uid);
    printf("文件所属组的:%d\n", file_info.st_gid);
    printf("特殊文件的设备号:%d\n", file_info.st_rdev);
    printf("文件大小:%d\n", file_info.st_size);
    printf("文件所占数据块数目:%d\n", file_info.st_blocks);
    printf("最近访问时间:%d\n", file_info.st_atime);
    printf("最近修改时间:%d\n", file_info.st_mtime);
    printf("最近属性更改时间:%d\n", file_info.st_ctime);
    printf("写数据块建议值:%d\n", file_info.st_blksize);


    return 0;
    
}
