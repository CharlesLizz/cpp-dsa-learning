#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
	ctype库简单学习、了解
*/

void count(char crr[], int len);

int main()
{

	//isdigit 0-9整数字符判断
	/*

	char c = '3';
	int r = isdigit(c);
	printf("%d\n", r);

	if (r)
	{
		printf("字符 %c 是数字字符\n", c);
	}

	*/

	//islower 小写字符判断

	//isupper 大写字符判断

	//isalpha 字母字符判断

	//isalnum 字母和数字判断

	//isspace 空白字符判断 ， 例如 \f换页,\n换行,\r回车，\t制表符，\v垂直制表符

	//case :给定一个字符数组，只能包含数字、大小写字母
	//要求：统计大小写字母与数字各自的个数


	/*

	char crr[] = "asdaASD123123";
	int len = (sizeof(crr) - 1) / sizeof(crr[0]);

	count(crr, len);

	*/


	/*
	================================字符串函数=============================
	*/

	//strlen ---字符串长度计算
	//strcpy ---字符串复制
	//strcat ---字符串连接
	//strcmp ---字符串比较
	//strncpy ---字符串限定长度复制

	//此处插入const相关内容
	/*

	int a = 10;
	const int* p = &a;
	int const* p = &a;

	上方两种写法意义一致，表示不能通过解引用赋值等方法修改指针p对应的值


	下方这种写法意义不同，不能修改p绑定的对象，
	比如	p=&b;等写法，但是可以通过解引用来修改a地址中对应的值
	即不能改变p的指向
	int* const p = &a;

	*/

	//strlen部分
	char* str = "hello";//此处无论是否加const，都无法修改str中的值，因为是常量
	int len = strlen(str);
	printf("%d\n", len);

	//此处输出为5意味着，strlen获取长度时遇到“\0”则停止计算，不会包括"\0"




	//strcpy，copy
	//char* strcpy(char* destination, const char* source);
	//						目的地					源

	char dest1[15] = { "hello" };
	const char* src = "abcdef";
	strcpy(dest1, src);
	printf("%s\n", dest1);
	/*

	1、为什么dest用的是数组而不是指针
		因为指针只是变量，存储的是地址，如果用指针接受，则未分配地址来存储
	2、为什么已经copy了，还有返回值
		方便链式函数，返回值与copy值一致

	*/


	//strcat，拼接字符串，字符串追加
	//char *strcat(char *dest, const char *src)
	//意为将src的值copy到dest后

	char dest2[15] = { "hello" };
	strcat(dest2, src);
	printf("%s\n", dest2);
	//原字符串中的"\0"会被覆盖


	//strcmp，比较
	/*
		int strcmp(const char *str1, const char *str2)
		把 str1 所指向的字符串和 str2 所指向的字符串进行比较
		从两个字符串的第一个字符开始比较，比较的值是二者的ASCII码
	*/
	char* str1 = "abcdefg";
	char* str2 = "abcdef";
	printf("%d\n", strcmp(str1, str2));
	//返回值为0，二者相等；返回值<0，前者小；返回值>0，后者大

	/*
	1、当两个字符串进行比较时，对应字符如果不一样，对应字符的大小就是整个字符串的大小
	2、如果比较的字符串中有一者先比较结束，遇到"\0"，则先执行结束的字符串小
	*/




	//strncpy，增加第三个参数
	/*
	char *strncpy(char *dest, const char *src, size_t n)
	把 src 所指向的字符串复制到 dest，最多复制 n 个字符。
	*/











	return 0;
}

void count(char crr[], int len)
{
	int count_num = 0;
	int count_upper = 0;
	int count_lower = 0;

	for (int i = 0;i < len;i++)
	{
		if (isdigit(crr[i]))
		{
			count_num++;
		}
		else if (isupper(crr[i]))
		{
			count_upper++;
		}
		else if (islower(crr[i]))
		{
			count_lower++;
		}
	}

	printf("count_num = %d\n", count_num);
	printf("count_upper = %d\n", count_upper);
	printf("count_lower = %d\n", count_lower);



}

