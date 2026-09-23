

#include <stdio.h>

/*

库函数：c语言已经实现的函数

自定义函数：自己封装实现的函数

函数语法格式:
	ret_type fun_name(形参)
	{
		语句
	}
	其中ret_type是函数返回类型
	fun_name是函数名
	括号中的是形式参数
	{}中的是函数体


*/
/*

函数声明：告诉编译器函数的返回类型、名称和参数
例如：
int add(int a, int b);

函数定义：真正实现函数的功能
例如：
int add(int a, int b)
{
	return a + b;
}

函数调用：使用函数
例如：
int ret = add(1, 2);

*/
int fac(int n);
int add(int a, int b);
int is_leap_year(int year);
void Reverse(int arr[], int len);
void Print(int arr[], int len);
void set_arr(int arr[], int len, int val);

//形参与实参按值传递；学习指针后，可以按地址传递
int main()
{

	int ret = add(1, 2);
	printf("ret = %d\n", ret);

	int res = fac(5);
	printf("res = %d\n", res);


	//int result = is_leap_year(2000);
	//printf("%s", result ? "闰年" : "平年");

	for (int year = 2000; year < 2026; year++)
	{
		int result = is_leap_year(year);
		printf("%d是%s\n", year, result ? "闰年" : "平年");

	}

	printf("\n===================\n");

	int arr[] = { 1,2,3,4,5,6,7,8 };
	int len = sizeof arr / sizeof arr[0];
	Reverse(arr, len);
	Print(arr, len);

	printf("\n");

	set_arr(arr, len, -1);
	Print(arr, len);










	return 0;
}


//求两个整数之和
int add(int a, int b)
{
	int ret = a + b;
	return ret;
}

//求n的阶乘
int fac(int n)
{
	int res = 1;
	for (int i = 1;i <= n;i++)
	{
		res *= i;
	}
	return res;
}

//判断是不是闰年

int is_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		return 1;
	}
	return 0;
}

//数组逆置

void Reverse(int arr[], int len)
{
	int i = 0;
	int j = len - 1;

	while (i < j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}


}
//数组打印
void Print(int arr[], int len)
{

	for (int i = 0; i < len; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}


//设计一个函数，传入一个数组，把所有元素都设置为入参

void set_arr(int arr[], int len, int val)
{
	for (int i = 0;i < len;i++)
	{
		arr[i] = val;
	}
}

/*

	函数的实参是数组，形参也可以写成数组形式

	形参如果是一维数组，数组大小可以忽略不写

	数组传参，形参是不会创建新的数组的

	形参操作的数组和实参的数组是同一个数组

	数组传参的本质：传递数组首地址

*/


/*
	也就是说，数组作为参数传递时，传递的是地址
*/