#include <stdio.h>
#include <stdbool.h>

//全局变量
int globel = 10;


int main() {

	/*
	==============================
	常见数据类型
	==============================
	*/

	// 字符
	signed char ch = 'A';       // 有符号 char：负数、0、正数
	// signed 可以省略
	unsigned char ch2 = 'B';    // 无符号 char：0、正数


	// 整型
	short sh = 10;
	int i = 10;
	long la = 100;
	long long lla = 100000;


	// 浮点
	float f = 12.5;
	double d = 12.5;
	long double ld = 12.5;


	// 布尔
	_Bool flg = true;

	if (flg) {
		printf("this is true!\n");
	}
	else {
		printf("false!\n");
	}


	/*
	==============================
	变量
	==============================
	格式：data_type name

	通过数据类型定义变量

	常见数据类型：

	基本类型：字符型、整型、浮点类型、布尔类型

	枚举：enum
	空类型：void

	派生类型：
	指针（*）
	数组（[]）
	结构体（struct）
	共用体（union）
	函数

	 */

	 //局部变量
	int local = 5;

	//如果全局变量与局部变量同名，局部变量优先级高于全局变量
	printf("%d\n", local);
	printf("%d\n", globel);



	printf("test------sizeof\n");
	//sizeof关键字----可以用于计算某个类型或者表达式的长度，单位是字节
	int a = 10;
	printf("%d\n", sizeof(a));			//求变量大小
	printf("%d\n", sizeof(int));		//求类型大小
	printf("%d\n", sizeof(3 + 3.5));	




	return 0;
}

/*
	变量命名规则：
	1. 只能包含：字母、数字、下划线 _
	2. 不能以数字开头
	3. 不能使用 C 的关键字
	4. 区分大小写


	存储区域与划分：

	局部变量		动态内存管理		全局变量
	函数参数							静态变量
	  栈区				堆区			 静态区


	8bit位=1byte（字节）

	各数据类型占用：


*/