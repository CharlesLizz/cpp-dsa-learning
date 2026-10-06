#include"SeqList.h"

//初始化结构体变量
/*
void SLInt(SL sl)
{
	sl.a = NULL;
	sl.size = 0;
	sl.capacity = 0;
}
*/

void SLInt(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->capacity = 0;
}


//2倍扩容
void SLCheckCapacity(SL* ps)
{
	assert(ps != NULL);
	//如果size == capacity，代表容量已满或者为初始化
	if (ps->size == ps->capacity)
	{
		if (ps->capacity == 0)
		{
			//初始化
			ps->capacity = INIT_CAPACITY;

		}
		else
		{
			//2倍扩容
			ps->capacity = 2 * ps->capacity;

		}
		SLDataType* tmp = realloc(ps->a, ps->capacity * sizeof(SLDataType));
		//确保realloc成功
		if (tmp == NULL)
		{
			//扩容失败
			perror("realloc失败了");
			return -1;
		}

		ps->a = tmp;

	}


}

//尾部插入数据
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps != NULL);

	//1、检查空间是否存在
	//2、检查是否有空余空间
	SLCheckCapacity(ps);
	//插入数据
	ps->a[ps->size++] = x;

	//ps->size++;

}

//打印输出
void SLPrint(SL* ps)
{
	assert(ps != NULL);
	//输出
	for (int i = 0;i < ps->size;i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//尾部删除数据
void SLPopBach(SL* ps)
{
	assert(ps != NULL);
	assert(ps->size != 0);

	//实际删除数据，其实不写下方这一句也可以，因为使用的是size，如果直接size--，
	//也能达到目的，使末位数据变成非有效数据

	//ps->a[ps->size] = NULL;

	ps->size--;

}

//头部插入数据
void SLPushFront(SL* ps, SLDataType x)
{

	//1、检查空间是否存在
	//2、检查是否有空余空间
	SLCheckCapacity(ps);
	//3、先从后往前挪动数据
	for (int i = ps->size - 1;i >= 0;i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	//头插
	ps->a[0] = x;

	ps->size++;
}

//头部删除数据
void SLPopFront(SL* ps)
{
	assert(ps != NULL);
	assert(ps->size != 0);
	for (int i = 0;i < ps->size - 1;i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;


}



