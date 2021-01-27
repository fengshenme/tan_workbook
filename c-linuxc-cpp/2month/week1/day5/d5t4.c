#include <stdio.h>
#include <stdlib.h>	// 默认在系统目录查找头文件

#include "list.h"	// 默认在当前目录查找头文件，或者在系统目录查找


// 声明一个内核链表节点结构体（俗称：大结构体）
typedef struct kernel_list
{
	// 1.数据域
	int data;

	// 2.指针域（俗称：小结构体）
	struct list_head list;	//（前后关系）
}kl_st, *kl_pt;

// 初始化内核链表
kl_pt kl_list_init(void);
// 打印链表所有数据（后序遍历）
// 打印链表所有数据（前序遍历）
// 添加数据到链表头
// 添加数据到链表尾
// 删除指定的数据节点

int main(int argc, char const *argv[])
{
	// 1.初始化一条内核链表（头节点）
	kl_pt head = kl_list_init();

	return 0;
}

// 初始化内核链表头节点
kl_pt kl_list_init(void)
{
	// 1.申请一块堆空间给头节点
	kl_pt head = malloc(sizeof(kl_st));
	if(head == NULL)
	{
		perror("head malloc failed");
		return NULL;
	}

	// 2.修改头节点的指针域，使它们都指向自身
	head->list.prev = &(head->list);
    head->list.next = &(head->list);

	// 3.将堆空间首地址返回
    return head;
}


