


#include <stdio.h>


//在同项目下add.c源文件中声明了一个int g_val = 10;
//通过extern关键字进行引入
//当为全局变量声明时增加static关键字，则无法引入当前文件并使用
//extern int g_val;

extern int Add(int x, int y);
void test();



int main()
{

	/*
		static 是静态的意思，可以用来修饰
		局部变量、全局变量、函数
	*/


	int i = 0;//局部变量
	for (i = 0;i < 5;i++)
	{
		test();
	}
	printf("\n");//换行

	//printf("%d\n", g_val);


	int ret = Add(1, 2);
	printf("%d ", ret);


	return 0;
}

void test()
{
	//int i = 0;

	/*

	这里如果不加static，则每次调用时，i都从0开始
	则main中调用5次，输出5个1
	从生命周期上来说，进入函数，i被创建，函数结束后被销毁
	所以不加static关键字不会累加

	*/
	static int i = 0;

	/*

	现在加入static关键字修饰
	本质上来说改变了这个局部变量的生命周期
	i不会随着函数的开始而创建、结束而销毁，只有程序结束时才被销毁
	所以再次调用5次时，i被累加

	static 局部变量：
	- 只初始化一次
	- 生命周期持续到整个程序结束
	- 多次调用函数时会保留上一次的值


	*/

	i++;
	printf("%d ", i);
}



/*

static修饰局部变量时，改变生命周期
修饰全局变量时，改变作用域

*/