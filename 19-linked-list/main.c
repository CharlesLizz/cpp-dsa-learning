/*
	链表：
		线性表的链式存储结构即为链表，从逻辑上来说是一定连续的
		但是 从物理上来说 不一定是连续的

		每个数据在链表当中是以 节点/结点 的方式进行存储
		节点/结点之间是以指针的方式串连在一起的

		每个节点中至少包含两个 “域”
			一个是值域
			一个叫“next域” => 存储下一个节点的地址

		plist是一个指针，存储的是第一个节点的地址；那么plist也叫头指针
		链表的第一个数据节点叫头节点
		最后一个节点称之为尾节点；特点：next域为NULL

		和顺序表不同，每个节点都做到了随用随取
			如插入一个数据的时候，只申请一个数据需要的空间

		节点是从堆上申请的空间，由于每次插入数据都需要重新申请
		所以链表的节点与节点之间物理内存不一定连续

		链表分类
			是否带头
			单向双向
			是否循环
		共有八种链表

		主要讲的是 不带头 单向且非循环 的链表
*/

#include "SList.h"

//通过这个函数来简单创建链表，来帮助理解
SLTNode* createList()
{
	SLTNode* node1 = malloc(sizeof(SLTNode));
	SLTNode* node2 = malloc(sizeof(SLTNode));
	SLTNode* node3 = malloc(sizeof(SLTNode));
	SLTNode* node4 = malloc(sizeof(SLTNode));


	node1->data = 12;
	node2->data = 23;
	node3->data = 34;
	node4->data = 45;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	return node1;
}


int main()
{
	/*
	SLTNode* plist = createList();
	SLTPrint(plist);
	*/

	SLTNode* plist = NULL;
	SLTPushFront(&plist, 12);
	SLTPushFront(&plist, 23);
	SLTPushFront(&plist, 34);
	SLTPrint(plist);

	SLTPopFront(&plist);
	SLTPrint(plist);

	return 0;
}