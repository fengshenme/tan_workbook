#! /bin/bash

# 动态库制作
# gcc -fPIC -shared src/*.c -o lib/libpool.so -I include
# 动态库的两种使用方式
gcc main/main.c -o main.out -I include -L ./lib -lpool -Wall -lpthread
# gcc main/main.c -o main.out -I include lib/*.so -Wall -lpthread

# ./project: error while loading shared libraries: libggy.so: cannot open shared object file: No such file or directory
# 执行project时出错了，因为在加载libggy.so动态库时，因为文件找不到而导致打开这个库失败。

# 6）告诉系统，去哪里找到这个库？
#    第一步：先把库拷贝到家目录。
#    cp libpool.so ~/lib    

#    第二步： 告诉系统去家目录下寻找库文件即可。
#    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/gec/lib        