



#include <stdio.h>

/*
	结构体概念(struct)
	用于组合多个相关数据项的复合（聚合）数据类型

	struct tag
	{

		member-list;//成员列表

	}variable-list;//变量列表

*/
struct Student
{
	char name[20];
	int age;
	char sex[5];
};

void print_struct(struct Student stu1)
{
	printf("name = %s\n", stu1.name);
	printf("age = %d\n", stu1.age);
	printf("sex = %s\n", stu1.sex);
}

void print_struct_pointer(struct Student* pstu)
{
	printf("name = %s\n", pstu->name);
	printf("age = %d\n", pstu->age);
	printf("sex = %s\n", pstu->sex);
}

/*
	=======================结构体别名=======================
*/

//typedef关键字
//写法1
typedef struct Student1
{
	char name[20];
	int age;
	char sex[5];
}stu1;
//写法2
struct Student2
{
	char name[20];
	int age;
	char sex[5];
};
typedef struct Student2 stu2;


int main()
{
	struct Student stu01 = { "张三",18,"男" };
	print_struct(stu01);

	struct Student* pstu = &stu01;
	printf("pstu = %p\n", pstu);
	//	->  指向符，等价于 先 解引用再打点取成员变量
	print_struct_pointer(pstu);

	//Q1:什么时候用“.”，什么时候用指向符“->”
	//A1:使用指向符时，前边必须是一个指针 
	// 即 结构体指针变量-> 结构体成员变量
	// 或 结构体变量.结构体成员变量

	//Q2:传参时，传结构体指针好，还是传结构体变量好？？
	//A2:传递结构体变量时，会复制整个结构体；
	//	 传递结构体指针时，只需要传递一个地址，可以避免复制较大的结构体。

	/*
		=======================结构体别名=======================
	*/

	//typedef关键字

	stu1 s1 = { "张三" ,18,"男" };
	stu2 s2 = { "李四" ,18,"男" };


	/*
		=======================结构体的内存对齐=======================
	*/

	/*
	结构体的第一个成员变量对齐到和结构体变量起始位置偏移量为0的地址处
	从第二个成员变量开始，都要对齐到某个对齐数的整数倍的地址处

	对齐数 = 编译器默认的对齐数 与 该成员变量 大小的 较小值
		--VS中默认的值为8
		--gcc没有默认对齐数，对齐数就是成员自身的大小

	结构体的总大小为最大对齐数的整数倍

	*/
	/*
		=======================联合体（共用体）=======================
	*/



	return 0;
}