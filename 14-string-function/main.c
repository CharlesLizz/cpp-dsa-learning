#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <ctype.h>
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


	char crr[] = "asdaASD123123";
	int len = (sizeof(crr) - 1) / sizeof(crr[0]);

	count(crr, len);
	/*
	================================字符串函数=============================
	*/

	//strlen ---字符串长度计算
	//strcpy ---字符串复制
	//strcat ---字符串连接
	//strcmp ---字符串比较
	//strncpy ---字符串限定长度复制









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

