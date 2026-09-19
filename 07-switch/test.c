
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
	/*
	Switch语句 是一种特殊的if...else结构，用于判断条件有多个结果的情况，
	他把多重的else...if改成更加易用、可读性更好的形式
	*/

	/*
	switch语法格式
	switch(expression)
	{
		case value1: statement
		case value2: statement
		case value3: statement
		case value4: statement
		...
		default: statement
	}


	*switch后的expression表达式必须是整型表达式
	* case后的值必须是整型常量表达
	*/

	/*

	1、每个case后必须有break
	2、case和后边的数字之间必须有空格
	3、default语句的作用是在没有合适的case进行匹配的时候执行

	*/

	//case 1
	int a;
	printf("输入一个数值进行匹配:");
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		printf("匹配到case1\n");
		break;
	case 2:
		printf("匹配到case2\n");
		break;
	case 3:
		printf("匹配到case3\n");
		break;
	case 4:
		printf("匹配到case4\n");
		break;

	default:
		printf("未正确匹配到\n");
	}


	//case 2
	//输入1-5，输出工作日；输入6-7，输出休息日
	int day;

	printf("输入日期：");
	scanf("%d", &day);
	switch (day)
	{
	case 1:

	case 2:

	case 3:

	case 4:

	case 5:
		printf("工作日\n");
		break;
	case 6:

	case 7:
		printf("休息日\n");
		break;
	default:
		printf("不是正确格式\n");
	}



	return 0;
}