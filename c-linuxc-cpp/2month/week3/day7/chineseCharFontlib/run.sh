# 将中英文显示 ,编码转换功能编译成动态库
# arm-linux-gnueabi-gcc -fPIC *.c -I ../include -o libFontch.so -shared -Wall
arm-linux-gnueabi-gcc $dir_name.c -I include lib/*.so -o dist/pro_c.out -Wall