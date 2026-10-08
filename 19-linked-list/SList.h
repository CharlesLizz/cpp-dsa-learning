
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;			//节点数据
	struct SListNode* next;		//指针保存下一个节点的地址
}SLTNode;


void SLTPrint(SLTNode* phead);

//头部插入删除
void SLTPushFront(SLTNode** pphead, SLTDateType x);
void SLTPopFront(SLTNode** pphead);

//尾部插入删除
void SLTPushBack(SLTNode** pphead, SLTDateType x);
void SLTPopBack(SLTNode** pphead);

//查找
SLTNode* SLTFind(SLTNode* phead, SLTDateType x);

//在指定位置之前插入数据
void SLTInsert(SLTNode** pphead, int pos, SLTDateType x);
//删除pos节点
void SLTErase(SLTNode** pphead, int key);
//销毁链表
void SListDesTroy(SLTNode** pphead);