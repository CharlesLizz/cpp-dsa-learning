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

//尾部插入
void SLTPushBack(SLTNode** pphead, SLTDateType x)
{
	assert(pphead != NULL);
	SLTNode* node = buyNode(x);

	if (*pphead == NULL)
	{
		*pphead = node;
	}
	else
	{
		//找尾巴
		SLTNode* pCur = *pphead;
		while (pCur->next != NULL)
		{
			pCur = pCur->next;
		}
		pCur->next = node;
	}
}

//尾部删除
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead != NULL && *pphead != NULL);

	SLTNode* pCur = *pphead;
	//如果只有一个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{	//法1
		//找尾巴的前驱节点
		while (pCur->next->next != NULL)
		{
			pCur = pCur->next;
		}
		free(pCur->next);
		pCur->next = NULL;

		//法2
		/*
		SLTNode* prev = NULL;
		SLTNode* ptail = *pphead;
		while (ptail->next != NULL)
		{
			prev = ptail;
			ptail = ptail->next;
		}
		//现在ptail是尾巴节点，prev是前驱节点
		free(ptail);
		prev->next = NULL;

		*/
	}
}
//查找
SLTNode* SLTFind(SLTNode* phead, SLTDateType x)
{
	assert(phead != NULL);
	SLTNode* pCur = phead;
	while (pCur != NULL)
	{
		if (pCur->data == x)
		{
			return pCur;
		}
		pCur = pCur->next;
	}
	return NULL;
}
//求链表长度
int GetLen(SLTNode* phead)
{
	assert(phead != NULL);
	SLTNode* pCur = phead;
	int count = 0;
	while (pCur != NULL)
	{
		count++;
		pCur = pCur->next;
	}
	return count;

}

//查找pos位置的前一个节点
SLTNode* findPrevOfPos(SLTNode* phead, SLTDateType pos)
{
	SLTNode* prev = phead;
	int count = 0;
	while (count != pos - 1)
	{
		prev = prev->next;
		count++;
	}
	return prev;
}

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, int pos, SLTDateType x)
{
	assert(pphead != NULL);
	int len = GetLen(*pphead);
	assert(pos >= 0 && pos <= len);
	if (pos == 0)
	{
		//头插法
		SLTPushFront(pphead, x);
		return;
	}
	if (pos == len)
	{
		//尾插法
		SLTPushBack(pphead, x);
		return;
	}
	//找插入节点的位置
	SLTNode* prev = findPrevOfPos(*pphead, pos);
	SLTNode* node = buyNode(x);

	node->next = prev->next;
	prev->next = node;
}


//删除关键字为Key的节点
void SLTErase(SLTNode** pphead, int key)
{
	assert(pphead != NULL && *pphead != NULL);

	if ((*pphead)->data == key)
	{
		//删除头节点
		SLTPopFront(pphead);
		return;
	}

	SLTNode* pCur = *pphead;
	//找到key对应的前一个节点
	while (pCur->next != NULL && pCur->next->data != key)
	{
		pCur = pCur->next;
	}

	if (pCur->next == NULL)
	{
		printf("没找到\n");
		return;
	}

	//删除对应节点
	SLTNode* keyNode = pCur->next;
	pCur->next = keyNode->next;
	free(keyNode);
}

//销毁链表
void SListDesTroy(SLTNode** pphead)
{
	assert(pphead != NULL);

	SLTNode* pCur = *pphead;
	while (pCur != NULL)
	{
		SLTNode* pNext = pCur->next;
		free(pCur);
		pCur = pNext;
	}
	*pphead = NULL;
}
