# 笔记

编译成动态库
```
gcc -Wall -Wextra -O -ansi -pedantic -shared test.cpp -o test.so
```

C 语言把任何非零和非空的值假定为 true，把零或 null 假定为 false。
c语言编译
```
gcc .\c00.c -o c00 -finput-charset=UTF-8 -fexec-charset=GBK
```

c++ 编译文件，输入文件编码utf-8，输出文件gbk编码 添加指定版本-g -Wall -std=c++14
```
g++ -lm .\cpp0.cpp -o ./cpp0 -finput-charset=UTF-8 -fexec-charset=GBK -g -Wall -std=c++14 
```
c两个源文件进行编译链接
```
gcc main.c support.c -o main -finput-charset=UTF-8 -fexec-charset=GBK 
```
c++两个源文件进行编译链接
```
g++ -lm .\store.cpp .\support.cpp -o .\store -finput-charset=UTF-8 -fexec-charset=GBK -g -Wall -std=c++14
```
在使用GCC编译器的时候，我们必须给出一系列必要的调用参数和文件名称。GCC编译器的调用参数大约有100多个，这里只介绍其中最基本、最常用的参数。具体可参考GCC Manual。
GCC最基本的用法是∶gcc [options] [filenames]
其中options就是编译器所需要的参数，filenames给出相关的文件名称。
-c，只编译，不链接成为可执行文件，编译器只是由输入的.c等源代码文件生成.o为后缀的目标文件，通常用于编译不包含主程序的子程序文件。
-o output_filename，确定输出文件的名称为output_filename，同时这个名称不能和源文件同名。如果不给出这个选项，gcc就给出预设的可执行文件a.out。
-g，产生符号调试工具（GNU的gdb）所必要的符号资讯，要想对源代码进行调试，我们就必须加入这个选项。
-O，对程序进行优化编译、链接，采用这个选项，整个源代码会在编译、链接过程中进行优化处理，这样产生的可执行文件的执行效率可以提高，但是，编译、链接的速度就相应地要慢一些。
-O2，比-O更好的优化编译、链接，当然整个编译、链接过程会更慢。
-Idirname，将dirname所指出的目录加入到程序头文件目录列表中，是在预编译过程中使用的参数。C程序中的头文件包含两种情况∶
A）#include <myinc.h>
B）#include “myinc.h”
其中，A类使用尖括号（< >），B类使用双引号（“ ”）。对于A类，预处理程序cpp在系统预设包含文件目录（如/usr/include）中搜寻相应的文件，而B类，预处理程序在目标文件的文件夹内搜索相应文件。
-v gcc执行时执行的详细过程，gcc及其相关程序的版本号
原版gcc manual该选项英文解释
Print （on standard error output） the commands executed to run the stages of compilation. Also print the version number of the compiler driver program and of the preprocessor and the compiler proper.
编译程序时加上该选项可以看到gcc搜索头文件/库文件时使用的搜索路径！
基本规则编辑
gcc所遵循的部分约定规则：
.c为后缀的文件，C语言源代码文件；
.a为后缀的文件，是由目标文件构成的档案库文件；
.C，.cc或.cxx 为后缀的文件，是C++源代码文件且必须要经过预处理；
.h为后缀的文件，是程序所包含的头文件；
.i 为后缀的文件，是C源代码文件且不应该对其执行预处理；
.ii为后缀的文件，是C++源代码文件且不应该对其执行预处理；
.m为后缀的文件，是Objective-C源代码文件；
.mm为后缀的文件，是Objective-C++源代码文件；
.o为后缀的文件，是编译后的目标文件；
.s为后缀的文件，是汇编语言源代码文件；
.S为后缀的文件，是经过预编译的汇编语言源代码文件。
语言支持编辑
以2006年5月24日释出的4.1.1版为准，本编译器版本可处理下列语言：
Ada 〈GNAT〉
C 〈GCC〉
C++（G++）
Fortran 〈Fortran 77: G77, Fortran 90: GFORTRAN〉
Java 〈编译器：GCJ；解释器：GIJ〉
Objective-C 〈GOBJC〉
Objective-C++
先前版本纳入的CHILL前端由于缺乏维护而被废弃。
Fortran前端在4.0版之前是G77，此前端仅支援Fortran 77。在本版本中，G77被废弃而采用更新的GFortran，因为此前端支援Fortran 95。
下列前端依然存在：
Modula-2
Modula-3
Pascal
PL/I
D语言
Mercury
VHDL
执行过程编辑
虽然我们称GCC是C语言的编译器，但使用gcc由C语言源代码文件生成可执行文件的过程不仅仅是编译的过程，而是要经历四个相互关联的步骤∶预处理（也称预编译，Preprocessing）、编译（Compilation）、汇编（Assembly）和链接（Linking）。
命令gcc首先调用cpp进行预处理，在预处理过程中，对源代码文件中的文件包含（include）、预编译语句（如宏定义define等）进行分析。接着调用cc1进行编译，这个阶段根据输入文件生成以.i为后缀的目标文件。汇编过程是针对汇编语言的步骤，调用as进行工作，一般来讲，.S为后缀的汇编语言源代码文件和汇编、.s为后缀的汇编语言文件经过预编译和汇编之后都生成以.o为后缀的目标文件。当所有的目标文件都生成之后，gcc就调用ld来完成最后的关键性工作，这个阶段就是连接。在连接阶段，所有的目标文件被安排在可执行程序中的恰当的位置，同时，该程序所调用到的库函数也从各自所在的档案库中连到合适的地方。
执行过程示例编辑
示例代码
#include<stdio.h>
 
int main（void）{
  
      printf（"hello\n"）;
 
     return 0;
    
}
预编译过程
这个过程处理宏定义和include，去除注释，不会对语法进行检查。
可以看到预编译后，代码从6行扩展到了910行。
gcc -E a.c -o a.i
cat a.c|wc -l
5
cat a.i|wc -l
910
编译过程
这个阶段，检查语法，生成汇编代码。
gcc -S a.i -o a.s
cat a.s|wc-l
59
汇编过程
这个阶段，生成目标代码。
此过程生成ELF格式的目标代码。
gcc -c a.s -o a.o
file a.o
a.o:ELF64-bitLSBrelocatable,AMDx86-64,version1（SYSV）,notstripped
链接过程
链接过程。生成可执行代码。链接分为两种，一种是静态链接，另外一种是动态链接。使用静态链接的好处是，依赖的动态链接库较少，对动态链接库的版本不会很敏感，具有较好的兼容性；缺点是生成的程序比较大。使用动态链接的好处是，生成的程序比较小，占用较少的内存。
1
gcc a.o -o a
程序运行：
./a
hello
处理器架构编辑
GCC4.1支持下列处理器架构：
Alpha
ARM
Atmel AVR
Blackfin
H8/300
IA-32〈x86〉 与x86-64
IA-64例如：Itanium
MorphoSys 家族
Motorola 68000
Motorola 88000
MIPS
PA-RISC
PDP-11
PowerPC
System/370，System/390
SuperH
HC12
SPARC
VAX
Renesas R8C/M16C/M32C家族
较不知名的处理器架构也在官方释出版本中支援：
A29K
ARC
C4x
CRIS
D30V
DSP16xx
FR-30
FR-V
Intel i960
IP2000
M32R
68HC11
MCORE
MMIX
MN10200
MN10300
NS32K
ROMP
Stormy16
V850
Xtensa
由FSF个别维护的GCC处理器架构：
D10V
MicroBlaze
PDP-10
MSP430
Z8000
当GCC需要移植到一个新平台上，通常使用此平台固有的语言来撰写其初始阶段。
程序除错编辑
为 GCC 除错的首选工具当然是 GNU 除错器。其他特殊用途的除错工具是 Valgrind, 用以发现内存漏失 （Memory leak）。而 GNU 测量器 （gprof） 可以得知程序中某些函式花费多少时间，以及其呼叫频率；此功能需要使用者在编译时选定测量〈profiling〉选项。
使用技巧编辑
首先检查是否在你的机器上安装了GCC，使用命令：
可用rpm -q gcc　检查。
如果没有安装，请依序检查并安装下面各RPM
libbinutils
binutils
make
glibc-devel
gcc-cpp
gcc
看下面的例子：test.c
#include<stdio.h>
 
int main（）
{
    char *str="I like Linux!I advice you to join in the Linux World";
    printf（"%s",str）;
    return 0;
}
使用gcc编译。输入gcc -c test.c得到目标文件test.o.-c命令表示对文件进行编译和汇编。但并不连接。如果再键入gcc -o ../bin/test test.o,那么将得到名为test的可执行文件。其实这两步可以一气呵成，gcc ../bin/test test.c.如果程序没有错误就生成了可执行文件。也许你会觉得基于命令行的编译器比不上如VC之类的集成开发环境，的确gcc的界面要改进，但是你一旦熟练了就会感到。gcc的效率如此之高。可以告诉大家的是Linux底下强大的C/C++集成开发环境Kdevelop和Vc一样强大，使用了Gcc编译器。
GNU C编译器 即gcc是一个功能强大的ANSI C兼容编译器，你会操作其他操作系统下的一种C编译器，能很快掌握GCC.
1、使用Gcc,Gcc是基于命令行的，使用时通常后跟一些选项和文件名。Gcc的基本用法如下： gcc [options] [filenames] 命令行选项制定操作将对命令行上的每个给出的文件执行。
2、GCC的常用选项
编译选项：gcc有超过100个的编译选项可用。具体的可以使用命令man gcc察看
优化选项：用GCC编译C/C++代码时，它会试着用最少的时间完成编译并且编译后的代码易于调试。易于调试意味着编译后的代码与源代码有同样的执行顺序，编译后的代码没有经过优化。有很多的选项可以告诉GCC在耗费更多编译时间和牺牲易调试性的基础上产生更小更快的可执行文件。这些选项中最典型的就是-O和-O2。-O选项告诉gcc对源代码进行基本优化。-O2选项告诉GCC产生尽可能小的和尽可能快的代码。还有一些很特殊的选项可以通过man gcc察看。
调试和剖析选项：GCC支持数种调试剖析选项。在这些选项中最常用的是-g和-pg.-g选项告诉gcc产生能被GNU调试器（如gdb）使用的调试信息，以便调试用户的程序。-pg选项告诉gcc在用户的程序中加入额外的代码，执行时，产生gprof用的剖析信息以显示程序的耗时情况。
3、使用gdb
使用方法：在命令行中键入gdb并按回车就可以运行gdb了，启动gdb后，能在命令行上制定很多的选项，也可以下面的方式来运行gdb: gdb filename 用这种方式运行gdb时，能直接指定想要调试的程序。在命令行上健入gdb -h得到一个有关gdb的选项的说明简单列表。
编译代码以供调试，为了使gdb工作，必须使程序在编译时包含调试信息，调试信息包含程序里的每个变量的类型，在可执行文件里的地址映射以及源代码的行号。gdb利用这些信息使源代码和机器码相关联。
关于gcc的大体就写这么多吧，更多的信息可以查找帮助，记得学习Linux的一大武器man或者info命令，下次在介绍一下使用C/C++编写大型程序的makefile文件和make命令。
版本发布编辑
2012年03月23日，GCC 首个公开发布版本是在 1987 年由 Richard Stallman 发布的，到今天已经整整 25 年了。为了庆祝 25 周年，GCC 也相应发布了 GCC 4.7.0 版本，这是 GCC 一个全新的重要版本。
GCC 4.7.0 带来了一组关于链接时优化 （LTO） 框架可提升伸缩性和降低内存使用，据开发者称，在 64 位系统上需要 8G 内存来对 Firefox 进行优化，然而用了 LTO 后只需 3G。
此外就是体验的支持软件事务内存，支持更多 C++11 标准，包括原子性、C++11 内存模型，用户定义文字、别名声明、构造器委派和可扩展的语法等。
GCC 4.7.0 还改进对 Fortran 的支持，支持 Google Go 1 等等多项改进。
2012年06月14日，GCC 4.7.1 发布了，这是一个 bug 修复版本，主要是 4.7.0 中的一些回归测试发现的问题修复。
2013年04月11日，GCC 4.7.3 发布。
2013年03月22日，GCC 4.8.0发布，进一步加强了对已C++11的支持。并且G++开始支持-std=c++1y选项，用来支持计划于2014年发布的C++11修订版标准（C++14）。 [3] 
2013年10月16日，GCC 4.8.2发布。提供了对于OpenMP 4.0的支持。
2014年04月22日，GCC发布了4.9.0版本，提供了对C11标准的Generic Selection语法特性（_Generic）的支持以及对多线程方面特性的支持。
安装方法编辑
linux中
RedHat中安装
用which gcc命令查看，假如有显示” /usr/bin/gcc”的话说明已经安装了，否则就是没有安装。
这里以redhat 64位 linux为例。首先将redhat的iso系统镜像挂在到/mnt/cdrom目录下：
　　mount -o loop /data/rhel-server-5.4-x86_64-dvd.iso /mnt/cdrom
　　进入/mnt/cdrom目录，就可以访问iso镜像中的内容了。
　　cd /mnt/cdrom
　　cd Server/
安装gcc的依赖包以及gcc，按以下命令依次执行：
　　rpm -ivh binutils-2.17.50.0.6-12.el5.x86_64.rpm
　　rpm -ivh cpp-4.1.2-46.el5.x86_64.rpm
　　rpm -ivh kernel-headers-2.6.18-164.el5.x86_64.rpm
　　rpm -ivh glibc-devel-2.5-42.x86_64.rpm
　　rpm -ivh glibc-headers-2.5-42.x86_64.rpm
　　rpm -ivh libgomp-4.4.0-6.el5.x86_64.rpm
　　rpm -ivh gcc-4.1.2-46.el5.x86_64.rpm
　　大家在安装rpm包时，由于依赖关系，在安装时会提示“此包依赖其他包xx”，让你先安装其他包，总之大家按照提示来，提示你先安装哪个包就安装哪个包。
Ubuntu中安装
安装4.8版为例：
sudo apt-get install gcc-4.8


18 300