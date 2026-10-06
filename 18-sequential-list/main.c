

#include"SeqList.h"


void test()
{
	//声明
	SL seq_list;
	//初始化
	SLInt(&seq_list);

	//尾插
	SLPushBack(&seq_list, 10);
	SLPushBack(&seq_list, 20);
	SLPushBack(&seq_list, 30);
	SLPushBack(&seq_list, 40);
	SLPushBack(&seq_list, 50);
	//打印
	SLPrint(&seq_list);

	/*

	//尾删
	SLPopBack(&seq_list);
	//打印
	SLPrint(&seq_list);

	printf("头部插入数据\n");

	//头插
	SLPushFront(&seq_list, 100);
	//打印
	SLPrint(&seq_list);
	printf("头部删除数据\n");

	//头删
	SLPopFront(&seq_list);
	//打印
	SLPrint(&seq_list);

	*/

	//指定位置插入数据
	printf("指定位置插入数据\n");
	SLInsert(&seq_list, 3, 3333);
	//打印
	SLPrint(&seq_list);

	printf("删除指定位置数据\n");
	//删除指定位置数据
	SLErase(&seq_list, 3);
	//打印
	SLPrint(&seq_list);

	//查找数据下标
	int ret = SLFind(&seq_list, 50);
	printf("ret = %d\n",  ret);

	//销毁
	printf("销毁\n");
	SLDestroy(&seq_list);
	SLPrint(&seq_list);

}

int main()
{


	/*
		线性表
			线性关系：每个元素都有且仅有一个直接的前驱元素和直接的后继元素
			有限序列：线性表是一个有限的元素集合
			同类型元素：线性表中的数据元素通常属于相同的数据类型

		线性表的存储结构分为两种：顺序存储结构、链式存储结构

		顺序表：也就是线性表的顺序存储结构
			指的是用一段地址连续的存储单元，依次存储线性表的数据元素，
			同时数据元素类型也是一致的（类似数组）

			顺序表的底层 其实就利用了数组来进行实现

			1、静态顺序表
				在程序编译的时候，就确定了该顺序表的大小，
				随着使用不断增加，即使出现了内存不够的情况，也无法增加

				应用场景：数据量固定且已知

			2、动态顺序表
				可以随着程序的需求来动态扩容，按需分配大小

				应用场景：数据量变化频繁或未知；查询数据库结果之后的信息存储；需要灵活内存管理


	*/

	test();

	/*
		顺序表适合查找的场景=》数据基本不变化
		但是插入和删除操作需要移动元素，比较麻烦，尤其是头部的插入和删除
		需要扩容，可能存在空间浪费的情况
	*/


	return 0;
}