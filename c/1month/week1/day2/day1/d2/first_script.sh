#!/bin/bash

echo "hello"

myname="Michael Jackson"

echo $myname

fruit=apple

mytree="$fruit tree"

today="today is `date`"

echo $mytree
echo $today

var=calender
echo "var: date"
echo "$var: `date`"
echo '$var: `date`'
# 条件判断
if test -e a.txt && test -r a.txt
then
    cat a.txt
fi
if [ -e a.txt ] && [ -r a.txt ]
then
cat a.txt
fi

if [ -e b.txt ] && [ -r b.txt ] #如果文件存在且可读，则显示该文件内容
then
    cat b.txt 
elif [ -e b.txt ] #  如果文件存在但不可读，则加了读权限之后再显示其内容
then
    chmod u+r b.txt
    cat b.txt
else
    touch b.txt # 如果文件不存在，则创建该空文件
fi

read VAR  # 从键盘接收一个用户输入
case $VAR in # 判断用户输入的值$VAR
	1) echo "one" # 如果$VAR的值为1，则显示one
		;;   # 每个分支必须都必须以双分号作为结束(最后一个分之除外)
	2) echo "two"
		;;
	*) echo "unknown" # 星号*是shell中的通配符，代表任意字符
esac 
# while循环语句
declare -i n=0        # 在定义变量n前面加上declare -i 表示该变量为数值
while [ $n -le 100 ]  # 如果n的值小于等于100，则循环
do 		      # 循环体用do和done包含起来
	echo "while---$n"
	n=$n+1	      # 使n的值加1
done
# until循环语句
declare -i n=0
until [ $n -gt 100 ]  # 如果n的值大于100，则退出循环
do
	echo "until-- $n"
	n=$n+1
done
# for循环语句 列出当前目录下每个普通文件所包含的行数
files=`ls`			# 在当前目录下执行ls，将所有的文件名保存在变量files中
for a in $files			# 循环地将files里面的每个单词赋值给a，完成后则退出循环
do
	if [ -f $a ] 		# 如果文件$a是一个普通文件，那么就计算它行数
	then
		wc -l $a
	fi
done

