#!/bin/bash

apt 
# 考点：类的封装：C++结构体的使用）
# 2、使用C++面向对象的思想，实现一个单链表
# C语言 ---- 定义一个结构体：数据域  指针域  ，定义一些操作链表的接口函数 -- 全局
# C++语言 ---- 定义一个结构体：数据域  指针域，将操作链表的接口函数封装到一个类

# gcc 2job.c -o 2job.out -Wall -std=gnu11
g++ 2job.cpp -o 2job.out -Wall -std=gnu++11

./2job.out

