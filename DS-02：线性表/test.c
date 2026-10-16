#define ElemType int
#include <stdio.h>
#include<stdlib.h>

typedef struct LNode {				//定义单链表节点数据			
	ElemType data;			//每个节点存放一个数据元素
	struct LNode* next;		//指针指向下一个节点
}LNode, * LinkList;

/*

//初始化一个空的单链表
_Bool InitList(LinkList* L)
{
	L = NULL;	//空表，暂时还没有任何节点
	return 1;
}

void test()
{
	LinkList L;		//声明一个指向单链表的指针
	//初始化一个空表
	InitList(&L);

	//。。。后续代码。。。。
}

*/

//初始化一个单链表（带头节点）
_Bool InitList(LinkList* L)
{
	L = (LNode*)malloc(sizeof(LNode));
	if (L == NULL)
		return 0;
	(*L)->next = NULL;
	return 1;
}

void test()
{
	LinkList L;		//声明一个指向单链表的指针
	//初始化一个空表
	InitList(&L);

	//。。。后续代码。。。。
}