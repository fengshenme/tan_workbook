
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


# 交叉编译安装jpeg的动态库和静态库 
# ./configure --prefix=/home/gec/install/dist --host=arm-linux-gnueabi
# make && make install >> install.log
#  字体显示库,编码转换功能,编译成动态库
# arm-linux-gnueabi-gcc -fPIC *.c -I ../include -o libFontch.so -shared -Wall
# 调用动态库 ,多线程,jpeg图片显示,支持中英文字符已点阵显示

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

# 交叉编译putty
# ./configure --prefix=/home/gec/install/dist/putty --host=arm-linux-gnueabi
# make >>../dist/putty.log
#  make install 


# 交叉编译zlib
# env CC=arm-linux-gnueabi-gcc ./configure --prefix=/home/gec/dist/zlib
# make && make install

# 交叉编译openssl
# ./config no-asm shared --prefix=/home/gec/dist/openssl --cross-compile-prefix=/usr/bin/arm-linux-gnueabi- 
# vim Makefile //删除 CFLAG= 中的-m64
# make && make install

# 交叉编译openssh
# autoreconf // 生成./configure
# ./configure --prefix=/home/gec/dist/openssh --with-zlib=/home/gec/dist/zlib LDFLAGS="-L/home/gec/dist/openssl/lib" CFLAGS="-I/home/gec/dist/openssl/include" --host=arm-linux-gnueabi
# make && make install

# 交叉编译putty
# ./configure --prefix=/home/gec/dist/putty --host=arm-linux-gnueabi
# make >>../dist/putty.log
# make install 

# 交叉编译openssl
# CC="gcc-8"./config no-asm shared -fPIC --prefix=/home/gec/dist/openssl --cross-compile-prefix=arm-linux-gnueabi- 
# make
# make install

# 编译安装qt
# 出现不识别arm-linux-gnueabi-g++ 则复制目录linux-arm-gnueabi-g++并改名为arm-linux-gnueabi-g++ 编译qt -arm版
# 还是不识别则安装 sudo apt-get install libc6-i386 64位Linux系统下无法兼容32位交叉编译器。安装32位库
# ./configure -verbose  -prefix /home/gec/qtds -xplatform arm-linux-gnueabi-g++ -opensource -release -confirm-license \
# -no-pch -shared -no-iconv -no-xcb -no-opengl -nomake examples -nomake tools -nomake tests \
# qt
# ./configure -prefix /home/gec/qtds -xplatform arm-linux-gnueabi-g++ -opensource -release -confirm-license \
# -linuxfb -no-pch -shared -no-opengl -nomake examples -nomake tools -nomake tests -skip qt3d -skip qtcanvas3d -skip qtcanvas3d \
# -skip qtmultimedia 

# x86_64 qt linux
# ./configure -prefix /home/gec/qtds -opensource -release -confirm-license \
#   -no-pch -shared -no-opengl -nomake examples \
#  -skip qt3d  -skip qtxmlpatterns -skip qtdeclarative -skip qtlocation\
#  -no-iconv -no-harfbuzz -no-evdev

# jpeg交叉编译
#./configure --prefix=/home/gec/jpeg-9d/armbuild  CC=arm-linux-gnueabi-gcc --host=arm-linux-gnueabi --enable-shared --enable-static
#./configure --prefix=/home/gec/jpeg-9d/x86build  --enable-shared --enable-static

# -l 连接动态库使用,需要把版本号去掉 比如库名libjpeg.so.9.4.0需要去掉版本号为libjpeg.so,才能找的到, 否则报错找不到
#  或者建立一个软链接 ln -s libjpeg.so.9.4.0 libjpeg.so
# arm-linux-gnueabi-gcc 1d.c -o 1d.out -I include -L . -ljpeg -Wall

# 移植 先移植alsa-lib这个库 再移植alsa-utils 
# ./configure --prefix=/home/gec/alsalib --host=arm-linux-gnueabi --disable-python
# alsa-utils 
# ./configure --prefix=/home/gec/alsalib --host=arm-linux-gnueabi \
# --with-alsa-prefix=/home/gec/alsalib/lib/ --with-alsa-inc-prefix=/home/gec/alsalib/include/ \
# --disable-alsamixer  --disable-xmlto 

