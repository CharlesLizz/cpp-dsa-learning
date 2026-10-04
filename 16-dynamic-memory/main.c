


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