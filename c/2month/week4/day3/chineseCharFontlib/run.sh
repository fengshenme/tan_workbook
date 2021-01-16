
#  -----------------day6----------------
# gcc x86_64平台的gcc编译
# aarch64-none-linux-gnu-gcc  arm平台的gcc编译
# arm-linux-gnueabi-gcc arm平台的gcc编译
# env CC=aarch64-none-linux-gnu-gcc ./configure --prefix=/home/gec/install/dist --host=aarch64-none-linux-gnu
# 两种编译arm-linux平台的方法 指定编译器 env CC=arm-linux-gnueabi-gcc
# env CC=arm-linux-gnueabi-gcc ./configure --prefix=/home/gec/install/dist --host=arm-linux-gnueabi-gcc
# Target: arm-linux-gnueabi  --host=指定软件运行的系统平台
#  编译到arm平台的库 ./configure --prefix=/home/gec/install/dist --host=arm-linux-gnueabi
# 显示图片 引用动态
# arm-linux-gnueabi-gcc src/d6t1.c -I include lib/libjpeg.s* -o dist/d33.out -Wall
# 引用静态
# arm-linux-gnueabi-gcc src/d6t1.c -I include lib/libjpeg.a -o dist/d33.out -Wall
# 显示图片从上,下落
# arm-linux-gnueabi-gcc src/d6t1.c -I include lib/libjpeg.s* 000000-o dist/d33.out -Wall
# 通过位运算,将4个16进制数拼接起来 month2/demo/ 目录下
# gcc month2/demo/d1.c  -o month2/demo/d33.out -Wall


# 将中英文显示 ,编码转换功能编译成动态库
# arm-linux-gnueabi-gcc -fPIC src/*.c -I include -o dist/lib/arm/libFontch.so -shared -Wall
# arm-linux-gnueabi-gcc $dir_name.c -I include lib/*.so -o dist/pro_c.out -Wall
# arm-linux-gnueabi-gcc $dir_name.c -I include -L lib -l*.so -o dist/pro_c.out -Wall



# ./config no-asm shared --prefix=/home/gec/install/dist/openssl --cross-compile-prefix=/usr/bin/arm-linux-gnueabi-

# env CC=arm-linux-gnueabi-gcc AR=arm-linux-gnueabi-ar RANLIB=arm-linux-gnueabi-ranlib ./config no-asm shared --prefix=/home/gec/install/dist/openssl 

# 【配置】：
# ./config no-asm shared --prefix=/home/mhc/openssl-install --cross-compile-prefix=/home/mhc/Local/arm-none-linux-gnueabi-

# 参数解释：
# 参数	描述
# no-asm	禁止使用汇编代码
# shared	编译成动态库
# --prefix	

# 指定之后make install后生成的执行文件跟库的存放位置（蓝色部分是我的）

# 也可以在执行./config之后修改Makefile中的INSTALLTOP变量
# --cross-compile-prefix	指定交叉编译工具位置及前缀（蓝色部分是我的）
# 【编译】 ：
# #make

# 可能会报错，报错则手动修改Makefile：去掉OPTIONS中的“-m64”


# 交叉编译zlib
# env CC=arm-linux-gnueabi-gcc ./configure --prefix=/home/gec/install/dist/zlib
# make && make install

# 交叉编译openssl
# ./config no-asm shared --prefix=/home/gec/install/dist/openssl --cross-compile-prefix=/usr/bin/arm-linux-gnueabi- 
# vim Makefile //删除 CFLAG= 中的-m64
# make && make install

# 交叉编译openssh
# ./configure --prefix=/home/gec/install/dist/openssh --with-zlib=/home/gec/install/dist/zlib LDFLAGS="-L/home/gec/install/dist/openssl/lib" CFLAGS="-I/home/gec/install/dist/openssl/include" --host=arm-linux-gnueabi
# make && make install


./configure --prefix=/home/gec/install/dist/putty --host=arm-linux-gnueabi