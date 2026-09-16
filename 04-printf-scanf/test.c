#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

/*

printf是一个库函数，引用自stdio.h库

printf可以在输出文件中任意指定占位符

*/
int main()
{
	SetConsoleOutputCP(CP_UTF8);

	printf("Change World\n");


	printf("there are %d apples and %d %s\n", 3 + 1, 6, "bananas");

	printf("%s will come\n", "I");


	/*

	占位符可以自定义宽度
	若不足，则在左侧增加空格；若超出或等于，则不改变

	默认右对齐

	*/
	printf("%5d\n", 123);       // 宽度为5，右对齐
	printf("%-5d\n", 123);      // 宽度为5，左对齐

	printf("%.1f\n", 0.5);      // 保留1位小数
	printf("%.2f\n", 0.5);      // 保留2位小数
	printf("%.3f\n", 0.5);      // 保留3位小数
	printf("%6.2f\n", 0.5);      // 保留2位小数，宽度为6


	/*

	scanf

	*/

	int a;
	int b;
	printf("请输入两个整数：");

	// 从键盘获取两个整数，分别写入 a 和 b
	// &a、&b 表示获取变量的地址

	/*

	无数据读取：如果没有读取或者匹配失败，则返回0

	Ctrl + Z + 回车
	可以向输入流输入 EOF
	scanf 遇到 EOF 时返回 EOF

	*/



	int ret = scanf("%d%d", &a, &b);

	printf("%d,%d\n", a, b);
	printf("%d", ret);//输出为2，正常情况返回成功读取的变量的个数




	return 0;
}