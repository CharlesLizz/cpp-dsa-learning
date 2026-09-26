

#include <stdio.h>

/*
	递归的主要思想：自我调用
	将原问题化为子问题

	递归必须包含：
	1. 递归条件：继续调用自身
	2. 终止条件：停止调用自身

	递归调用阶段：
	不断把问题拆小

	回归阶段：
	最底层返回结果后，
	逐层返回并计算结果


*/
//递推公式：N！= N * (N-1)！
int Fact(int N);
int Sum(int N);
int Fib(int N);
int Pow(int n, int k);

int main()
{
	//case1
	int ret1 = Fact(5);
	printf("%d\n", ret1);

	//case2
	int ret2 = Sum(100);
	printf("%d\n", ret2);

	//case3
	int ret3 = Fib(4);
	printf("%d\n", ret3);

	//case4
	int ret4 = Pow(2, 5);
	printf("%d\n", ret4);


	return 0;
}

//case 1 ：递归求N的阶乘
int Fact(int N)
{
	if (N <= 1)
	{
		return 1;
	}

	return N * Fact(N - 1);

}

//case 2 : 递归求1+2+3+...+N的和
int Sum(int N)
{
	if (N == 1)
	{
		return N;
	}

	return N + Sum(N - 1);

}

//case 3 :递归求斐波那契数列
int Fib(int N)
{
	if (N <= 1)
	{
		return N;
	}

	return Fib(N - 1) + Fib(N - 2);
}


//case 4 :编写一个函数，使用递归求n的k次方
int Pow(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}

	return n * Pow(n, k - 1);
}