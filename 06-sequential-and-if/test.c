#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
int main() {
	/*
	选择结构
	if语句
	// ① if
	if (条件)
	{
		语句;
	}

	// ② if...else
	if (条件)
	{
		语句1;
	}
	else
	{
		语句2;
	}

	// ③ if...else if...else
	if (条件1)
	{
		语句1;
	}
	else if (条件2)
	{
		语句2;
	}
	else
	{
		语句3;
	}
	若表达式为真，则执行语句

	*/
	printf("练习一\n");
	int n;
	printf("输入一个数来判断奇偶性:");
	scanf("%d", &n);
	if (n % 2 != 0)
	{
		printf("这是奇数\n");
	}
	else
	{
		printf("这是偶数\n");
	}

	printf("练习二\n");
	/*
	输入一个年龄，>=18则输出成年
	否则输出未成年
	*/
	printf("输入年龄：");
	int age;
	scanf("%d", &age);
	if (age >= 18)
	{
		printf("成年\n");
	}
	else
	{
		printf("未成年\n");
	}

	/*
	==========================
	逻辑运算符
	==========================

	&&  逻辑与(并且)（全真才真）
	||  逻辑或(或者)（一真就真）
	!   逻辑非
	*/

	/*
	
	test1:输入一个月份，如果在3-5月之间，则输出春天
	
	*/
	int month;
	printf("输入一个月份判断是否是春天:");
	scanf("%d", &month);
	if (month >= 3 && month <= 5)
	{
		printf("春天\n");
	}
	else
	{
		printf("这不是春天\n");
	}


	/*

	test2:输入一个月份，如果在3-5月之间，则输出春天

	*/
	int month2;
	printf("输入一个月份判断是否是冬天:");
	scanf("%d", &month2);
	if (month2 == 12 || month2 == 1 || month2==2)
	{
		printf("冬天\n");
	}
	else
	{
		printf("这不是冬天\n");
	}







	return 0;
}





/*
顺序结构：
程序默认从上到下依次执行

if：
根据条件决定是否执行某段代码

if
if...else
if...else if...else

C 中：
0 → 假
非0 → 真

if 可以嵌套

else 默认匹配最近的 if
*/