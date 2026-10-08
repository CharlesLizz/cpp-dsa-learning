#include"SList.h"


//打印链表data域
void SLTPrint(SLTNode* phead)
{
	assert(phead != NULL);
	SLTNode* pCur = phead;
	//此处也可以使用do-while循环，以pCur->next!=NULL为条件
	while (pCur != NULL)
	{
		printf("%d ", pCur->data);
		pCur = pCur->next;
	}
	printf("\n");
}

//创建节点
SLTNode* buyNode(SLTDateType x)
{
	SLTNode* node = malloc(sizeof(SLTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	node->data = x;
	node->next = NULL;
	return node;
}


//头部插入
void SLTPushFront(SLTNode** pphead, SLTDateType x)
{
	//Q1：为什么要传递二级指针？
	//A1：如果传递的是一级指针，则无法有效的更改实参的值

	assert(pphead != NULL);

	//步骤1：首先要申请一块空间 malloc
	SLTNode* node = buyNode(x);

	node->next = *pphead;
	*pphead = node;

}
//头部删除
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead != NULL);
	//至少有一个节点
	assert(*pphead != NULL);

	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

