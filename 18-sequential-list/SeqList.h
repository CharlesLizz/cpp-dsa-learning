#pragma once
#define INIT_CAPACITY 4
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


//给int起别名,此处用于规范，如果需要更改为char或者其他基础数据类型，直接修改此处的typedef即可
typedef int SLDataType;
//动态顺序表 -- 按需申请
typedef struct SeqList
{
	SLDataType* a;
	int size;		//有效数据个数
	int capacity;	//空间容量
}SL;


//初始化与销毁
//初始化结构体变量

//void SLInt(SL sl);
void SLInt(SL* ps);

//2倍扩容
void SLCheckCapacity(SL* ps);

//尾部插入数据
void SLPushBack(SL* ps, SLDataType x);

//打印输出
void SLPrint(SL* ps);

//尾部删除数据
void SLPopBach(SL* ps);

//头部插入数据
void SLPushFront(SL* ps, SLDataType x);

//头部删除数据
void SLPopFront(SL* ps);



