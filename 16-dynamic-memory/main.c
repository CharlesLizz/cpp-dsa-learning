


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



int main()
{

	/*
		动态内存分配malloc
			价值体现在运行时的灵活性
		函数原型：
			void *malloc(size_t size)

		通过malloc函数，我们可以向 堆区 申请分配一块连续的内存
		成功后返回这个内存的首地址
		如果失败则返回一个NULL指针


	*/
	int n = 5;
	int* p = (int*)malloc(n * sizeof(int));

	//debug判断malloc内存是否申请成功
	assert(p != NULL);
	//release判断malloc内存是否申请成功
	if (p == NULL)
	{
		printf("申请失败\n");
		return -1;
	}
	else
	{
		printf("%p\n", p);
	}


	//为内存填入值
	for (int i = 0; i < n; i++)
	{
		*(p + i) = i + 1;

	}
	//打印
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(p + i));

	}
	printf("\n");
	//由于这块空间在堆上，只要是堆上的空间，就需要手动通过free方法释放空间
	/*
		free
		void free(void* ptr);
	*/

	//释放内存
	free(p);
	p = NULL;
	//但是如果只释放p，现在p就是野指针，还需要给p指向NULL

	//free只能释放动态分配的内存
	//非动态开辟的内存，即栈上的内存，不能通过free手动释放；此时free行为是未定义的
	//如果参数ptr是NULL指针，则函数什么事都不做
	//如果不使用free释放，则可能造成内存泄漏



	/*
		===========================calloc动态内存分配===========================
	*/
	//与malloc不同，calloc默认分配的内存是0
	//函数原型：void *calloc(size_t nitems, size_t size)

	int m = 5;
	int* p1 = (int*)calloc(m, sizeof(int));

	//debug判断malloc内存是否申请成功
	assert(p1 != NULL);
	//release判断malloc内存是否申请成功
	if (p1 == NULL)
	{
		printf("申请失败\n");
		return -1;
	}
	else
	{
		printf("%p\n", p1);
	}


	//打印
	for (int i = 0; i < m; i++)
	{
		printf("%d ", *(p1 + i));

	}
	//输出 0 0 0 0 0 ，默认分配为0

	//释放内存
	free(p1);
	p1 = NULL;


	/*
		===========================realloc动态内存分配===========================
	*/
	/*
		让动态内存管理更灵活；
		realloc可以做到对动态开辟的内存灵活调整
		函数原型：void *realloc(void *ptr, size_t size)

		参数与返回值说明
			1、ptr是要调整的内存地址
			2、size是调整后的新大小，单位是字节
			3、返回值是调整之后的内存起始位置
			4、在调整原内存空间大小的基础上，还会将原来内存中的数据 移动到新的空间


	情况1：原有空间之后，有足够大的空间
		则直接 扩容
	情况2：原有空间之后，没有足够大的空间
		则在堆空间中重新申请一块足够大的 连续空间
	*/
	printf("\n");

	int n3 = 5;
	int* p3 = (int*)malloc(n * sizeof(int));//现在申请分配了20个字节的空间

	//debug判断malloc内存是否申请成功
	assert(p3 != NULL);
	//release判断malloc内存是否申请成功
	if (p3 == NULL)
	{
		printf("申请失败\n");
		return -1;
	}
	else
	{
		printf("%p\n", p3);
	}


	//为内存填入值
	for (int i = 0; i < n3; i++)
	{
		*(p3 + i) = i + 1;

	}
	//打印
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(p3 + i));

	}
	printf("\n");

	//使用realloc，扩容到40个字节

	int* ptr = (int*)realloc(p3, 2 * n * sizeof(int));

	printf("===========分割线===========\n");


	//打印
	for (int i = 0; i < 2 * n; i++)
	{
		printf("%d ", *(ptr + i));

	}
	free(ptr);
	ptr = NULL;

	//Q1:realloc函数一定能分配成功吗？
	/*
		p3 = (int*)realloc(p3, 2 * n * sizeof(int));
		如果realloc失败了，返回NULL，那么p3接受后，会导致原数据丢失
	*/











	return 0;
}





//case 
//LeetCode 1929
int* getConcatenation(int* nums, int numSize, int* returnSize)
{
	int* ans = (int*)malloc(numSize * 2 * sizeof(int));

	for (int i = 0;i < numSize;i++)
	{
		ans[i] = nums[i];
		ans[i + numSize] = nums[i];
	}

	*returnSize = numSize * 2;
	return ans;
}