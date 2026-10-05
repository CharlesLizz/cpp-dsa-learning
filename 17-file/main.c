

#include <stdio.h>


/*
	绝对路径：从系统根目录开始描述文件位置
		具有唯一性
	相对路径：从当前文件目录开始描述文件位置
		起点可变

	在项目当中，一般推荐使用相对路径
*/


/*
	文件是计算机中用于存储数据的基本单位，由操作系统统一管理
	本质是存储在存储介质上的命名数据集合，通过文件系统进行组织、访问和控制

	从存储内容上来说，可以分为
		文本文件和二进制文件

	程序需要特定组织结构来进行解析

	数据流
		输入输出是数据传输的过程，数据如流水一样从一处流向另一处
		数据流表示了信息从 源到目的地 的流动


	文件缓冲区
		系统自动在内存区，为程序中每一个正在使用的文件开辟一个文件缓冲区


	文件信息区
		每个正在被使用的文件都在内存当中开辟了一个相应的文件信息区，来存放文件的有关信息
		这些信息被保存在一个结构体变量中，由系统声明，名为file

*/
int main()
{
	//函数原型FILE* fopen(const char* _FileName,const char* _Mode);
	//如果打开成功，则返回一个指向FILE对象的指针；否则返回一个NULL指针

	/*
	"r" 打开一个用于读取的文件。该文件必须存在。
	"w" 创建一个用于写入的空文件。如果文件名称与已存在的文件相同，则会删除已有文件的内容，文件被视为一个新的空文件。
	"a" 追加到一个文件。写操作向文件末尾追加数据。如果文件不存在，则创建文件。
	"r+"打开一个用于更新的文件，可读取也可写入。该文件必须存在。
	"w+"创建一个用于读写的空文件。
	"a+"打开一个用于读取和追加的文件。
	*/
	FILE* pf = fopen("./input.txt", "rb");
	if (pf == NULL)
	{
		printf("文件打开失败\n");
		return 1;
	}
	printf("文件打开成功\n");

	//===================fputc函数===================
	//函数原型int fputc(int char, FILE *stream)
	//将char指定的字符写入到stream指向的输出流中，
	//通常用于向文件或者标准输出流（stdout）写入字符


	/*
	fputc('h', pf);
	fputc('e', pf);
	fputc('l', pf);
	fputc('l', pf);
	fputc('o', pf);
	*/

	/*

	char crr[] = { "hello" };
	int len = sizeof(crr) / sizeof(crr[0]);
	for (int i = 0;i < len - 1;i++)
	{
		fputc(crr[i], pf);
	}

	*/

	//===================fgetc函数===================
	//从参数stream指向的流中读取一个字符
	// 该函数以无符号 char 强制转换为 int 的形式返回读取的字符，
	// 如果到达文件末尾或发生读错误，则返回 EOF。
	//函数原型int fgetc(FILE *stream)

	/*

	int ch = -1;
	while ((ch = fgetc(pf)) != EOF)
	{
		printf("%c ", ch);
	}

	*/

	//===================fputs函数===================
	//函数原型int fputs(const char *str, FILE *stream)
	//将参数 str指向的字符串写入到参数stream指定的流中(不包含结尾的\0)

	/*

		const char* str = "liujiaxuan";

		fputs(str, pf);

	*/

	//===================fgets函数===================
	//函数原型char *fgets(char *str, int n, FILE *stream)
	/*

		str -- 这是指向一个字符数组的指针，该数组存储了要读取的字符串。
		n -- 这是要读取的最大字符数（包括最后的\0）。通常是使用以 str 传递的数组长度。
		stream -- 这是指向 FILE 对象的指针，该 FILE 对象标识了要从中读取字符的流。

	*/


	/*

		char str[100];
		fgets(str, sizeof(str), pf);
		printf("%s\n", str);

	*/

	//===================fwrite函数===================
	// 
	// 常用于二进制文件数据写入
	// 
	//函数原型：size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
	/*
	把 ptr 所指向的数组中的数据写入到给定流 stream 中
	ptr -- 这是指向要被写入的元素数组的指针。
	size -- 这是要被写入的每个元素的大小，以字节为单位。
	nmemb -- 这是元素的个数，每个元素的大小为 size 字节。
	stream -- 这是指向 FILE 对象的指针，该 FILE 对象指定了一个输出流。

	*/

	/*
	int arr[] = { 1,2,3,4,5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int count = fwrite(arr, sizeof(int), len, pf);

	if (count != len)
	{
		perror("fwrite");
		printf("文件写入失败\n");
		return -1;
	}
	*/


	//===================fread函数===================
	//函数原型：size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)

	/*
	从给定流 stream 读取数据到 ptr 所指向的数组中

	ptr -- 这是指向带有最小尺寸 size*nmemb 字节的内存块的指针。
	size -- 这是要读取的每个元素的大小，以字节为单位。
	nmemb -- 这是元素的个数，每个元素的大小为 size 字节。
	stream -- 这是指向 FILE 对象的指针，该 FILE 对象指定了一个输入流。

	*/


	int arr[5];
	int len = sizeof(arr) / sizeof(arr[0]);
	int size = fread(arr, sizeof(int), len, pf);
	if (size != len)
	{
		perror("fread");
		printf("文件读取失败\n");
		return -1;
	}
	//输出
	for (int i = 0;i < len;i++)
	{
		printf("arr[%d] = %d \n", i, arr[i]);
	}



	printf("\n");
	//关闭文件
	int ret = fclose(pf);
	pf = NULL;//指针置空
	printf("ret = %d\n", ret);


	return 0;
}