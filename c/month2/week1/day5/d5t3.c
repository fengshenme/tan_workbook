#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 声明一个单向循环链表
typedef struct sc_list
{
	// 1.数据域
	int data;

	// 2.指针域
	struct sc_list *next;
}node_st, *node_pt;

/******************函数声明*********************/
// 初始化单向链表
node_pt link_list_init(void);
// 打印链表所有数据（遍历）
void link_list_show(node_pt head);
// 添加数据到链表头
int link_list_add(int new_data, node_pt head);
// 添加数据到链表尾
int link_list_add_tail(int del_data, node_pt head);
// 删除指定的数据节点
int link_list_del(int del_data, node_pt head);
// 翻转链表
void link_list_flip(node_pt head);

int main(int argc, char const *argv[])
{
	// 1.初始化单向链表（存储总人数n）
	node_pt head = link_list_init();

	// 2.输入一个总人数n，并把 1~n 插入到链表中
	int n;
	fprintf(stderr, "Pls Input: \n");
	scanf("%d", &n); while(getchar()!='\n');

	int i;
	for(i=1; i<=n; i++)
		link_list_add_tail(i, head);
	link_list_show(head);

	// 3.开始循环，数3出局
	node_pt pos = head;
	while(1)
	{
		// 3.1 判断是否少于2人，break结束！
		if(n <= 2)
		{
			printf("Less than 2, DONE!\n");
			break;
		}

		// 3.2 数3（pos走3次，中间如果数到head，再数1次）
		for(i=0; i<3; i++)
		{
			pos = pos->next;
			if(pos == head)
				pos = pos->next;
		}

		// 3.3 杀人（删除该节点pos）
		printf("Kill: %d\n", pos->data);
		link_list_del(pos->data, head);

		// 3.4 剩余人数-1
		n--;
	}

	// 4.打印2名幸存者（打印链表剩余数据）
	link_list_show(head);






/*
	//操作
	int num;
	while(1)
	{
		fprintf(stderr, "Pls Input: ");
		scanf("%d", &num); while(getchar()!='\n');

		if(num > 0)
		{
			// 插入该数据
			link_list_add_tail(num, head);
		}
		else if(num < 0)
		{
			// 删除该数据
			link_list_del(-num, head);
		}
		else
		{
			//定义一个遍历指针pos，指向第一个数据节点
			node_pt pos = head->next;				
			while(1)
			{
				// 遍历每一个数据
				printf("%d\n", pos->data);
				pos = pos->next;
					// （遍历到头节点，再往后走一步）
				if(pos == head)
					pos = pos->next;

				sleep(1);
			}
		}
		// 显示链表所有数据
		link_list_show(head);

	}
*/
	return 0;
}


// 翻转链表
void link_list_flip(node_pt head)
{
	// 1.遍历链表，找出尾节点，记录地址  pos_tail
	node_pt pos_tail=head;
	while(pos_tail->next != head)
		pos_tail = pos_tail->next;

	// 2.重新开始遍历链表pos，逐个将每个节点移动到 pos_tail 的后面
	int data_pos;
	node_pt pos_temp;

	node_pt pos;
	for(pos=head->next; pos!=pos_tail; pos=pos_temp)
	{
		// （移动：删除节点+添加新节点）
		//（温馨提示：需要记录pos的后节点地址，否则被释放了不能访问了）
	// 直到移动到pos_tail位置，停止
		data_pos = pos->data;	//记录当前节点的数据（数据域）
		pos_temp = pos->next;	//记录后一个节点地址（指针域）

		link_list_del(data_pos, head);
		link_list_add(data_pos, pos_tail);
	}
}


// 初始化单向循环链表
node_pt link_list_init(void)
{
	// a. 头节点申请一个堆空间
	node_pt head = malloc(sizeof(node_st));
	if(head == NULL)
	{
		perror("head malloc failed");
		return NULL;
	}
	// b. 让头节点的指针域next指向它本身
	head->next = head;

	// c.将申请的堆空间返回
	return head;
}

// 添加数据到链表头
int link_list_add(int new_data, node_pt head)
{
	// a. 给新节点分配一个堆空间
	node_pt new_node = malloc(sizeof(node_st));
	if(new_node == NULL)
	{
		perror("new_node malloc failed");
		return 1;
	}

	// b. 把数据给入新节点数据域
	new_node->data = new_data;

	// c. 修改指针（不能调换）
	// 	1. 把头节点的指针域, 赋值给新节点的指针域（偷过来）
	// 	（让新节点next指向头节点的next）
	new_node->next = head->next;

	// 	2. 把新节点的地址，赋值给头节点的指针域
	// 	（让头节点next指向新节点）
	head->next = new_node;

	return 0;
}

// 添加数据到链表尾
int link_list_add_tail(int new_data, node_pt head)
{
	// A. 新节点分配堆空间
	node_pt new_node = malloc(sizeof(node_st));
	if(new_node == NULL)
	{
		perror("new_node malloc failed");
		return 1;
	}
	// B. 把数据给入新节点数据域
	new_node->data = new_data;

	// C. 找出尾节点（遍历链表，找出指针域指向NULL的节点）
	node_pt pos = head;
	while(pos->next != head)
		pos=pos->next;
		
	// D. 修改指针
		// 1. 新节点指针域，指向尾节点的指针域（偷）
	new_node->next = pos->next;
		// 2. 让尾节点的指针域，指向新节点
	pos->next = new_node;

	return 0;
}

// 删除指定的数据节点
int link_list_del(int del_data, node_pt head)
{
	// A. 判断是否为空链
	if(head->next == head)
	{
		printf("Empty!\n");
		return 1;
	}

	// B. 遍历链表，找出待删除数据的地址（需要两个指针同步移动），记录
	node_pt pos=head->next;
	node_pt pos_prev=head;
	// for(pos=head->next, pos_prev=head; pos!=NULL; pos_prev=pos, pos=pos->next)
	for(; pos!=head; pos_prev=pos, pos=pos->next)
	{
		if(pos->data == del_data)
			break;
	}
	// （如果遍历结束没找到，pos指向head，结束函数）
	if(pos == head)
	{
		printf("Not Found!\n");
		return 2;
	}

	// C. 修改指向即可
	// 让待删除节点的前节点的指针域，指向后节点。
	pos_prev->next = pos->next;

	// D.释放待删除节点的堆空间
	free(pos);

	return 0;
}


// 打印链表所有数据（遍历）
void link_list_show(node_pt head)
{
	printf("=========DATA========\n");
	node_pt pos;
	for(pos=head->next; pos!=head; pos=pos->next)
		printf("%d ", pos->data);
	printf("\n");
}

