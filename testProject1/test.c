#include <stdio.h>
#include <stdbool.h>


int main() {

	/*
	==============================
	字符、字符串以及 ASCII
	==============================

	printf() —— 输出
	%c —— char —— 字符
	%d —— decimal —— 十进制整数
	%s —— string —— 字符串
	%f —— float —— 浮点数
	%p —— pointer —— 指针/地址

	scanf() —— 输入
	getchar() —— 读取一个字符
	putchar() —— 输出一个字符

	文件操作：
	fopen()
	fclose()
	fread()
	fwrite()
	fprintf()
	fscanf()
	*/

	printf("Hello C\n");

	/*
	printf()
	引用自 stdio.h
	*/

	printf("%c\n", 'A');
	printf("%c\n", 65);


	


	return 0;
}


	/*
	总结：

	1. 字符和字符串不是一回事

	'A'     → 字符
	"ABC"   → 字符串


	2. 字符串的结束标志为 \0

	例如：

	"ABC"

	实际存储形式可以理解为：

	'A' 'B' 'C' '\0'


	3. ASCII

	'A' = 65
	'a' = 97
	'0' = 48

	A-Z 大写字母与对应的小写字母 ASCII
	编码相差 32。

	0-31 为 ASCII 中的控制字符，
	其中很多字符是不可打印的。


	
	*/