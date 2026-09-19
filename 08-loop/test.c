#include <stdio.h>
int main()
{
	/*
	while循环
	while(表达式）
	{
		语句块；
	}

	只要表达式为真，就执行语句块并循环；然后再次判断表达式
	*/

	//case 1 输出1-10
	int i = 1;
	while (i <= 10)
	{
		printf("%d ", i);
		i++;
	}

	printf("\n");
	//case 2 求5的阶乘
	int num = 1;
	int ret = 1;
	while (num <= 5) {
		ret *= num;
		printf("第%d步的ret = %d\n", num, ret);
		num++;
	}
	printf("5的阶乘为%d\n", ret);



	/*
	for循环
	for(表达式1;表达式2;表达式3)
	{
		语句块；
	}

	表达式1：初始化
	表达式2：判断条件
	表达式3：调整，每次循环执行
	*/


	//case 1: 求1-100之间2的倍数 数字之和
	int sum = 0;
	for (int j = 1; j <= 100; j++)
	{
		if (j % 2 == 0)
		{
			sum += j;
		}
	}
	printf("1-100之间2的倍数 数字之和 sum = %d\n", sum);


	/*
	do while循环
	do
	{
		语句；
	}while(表达式);

	先执行一次循环体，再判断条件；
	如果条件为真，继续下一次循环；
	如果条件为假，结束循环。

	**循环体至少执行一次。

	*/

	int k = 1;
	do
	{
		printf("%d ", k);
		k++;
	} while (k <= 10);
	printf("\n");
	/*
	循环的嵌套
	*/
	//-----------九九乘法表-----------
	int x, y;
	for (x = 1; x <= 9; x++)
	{
		for (y = 1; y <= x; y++)
		{
			printf("%d * %d = %d ", y, x, x * y);
		}
		printf("\n");
	}



	//case :最大公约数及最小公倍数
	int a = 8;
	int first_a = a;
	int b = 12;
	int first_b = b;

	int c = a % b;

	while (c != 0)
	{
		a = b;
		b = c;
		c = a % b;
	}
	printf("最大公约数为：%d\n", b);

	printf("最小公倍数为：%d\n", b * (first_a / b) * (first_b / b));

	//统计1-100中9出现的次数
	int count = 0;
	for (int i = 1;i <= 100;i++)
	{
		if (i % 10 == 9)
		{
			count++;
		}
		if (i / 10 == 9) {
			count++;
		}
	}
	printf("1-100中9出现的次数为：%d\n", count);


	// break：立即结束当前所在的循环
	//eg.1:
	int ii = 1;
	while (ii <= 10)
	{
		if (ii == 5)
		{
			break;
		}
		printf("%d ", ii);
		ii++;

	}
	printf("\n");

	//case 1 ：找到1-100之间第一个能被3整除的数字
	int num3 = 1;
	while (num3 <= 100)
	{
		if (num3 % 3 == 0)
		{
			printf("1-100中第一个能被3整除的数字是：%d\n", num3);
			break;
		}
		num3++;
	}

	// continue：跳过本次循环剩余代码，直接进入下一次循环判断
	
	//case 2 :找到1-100中所有能被3整除的数字
	int num4;
	printf("1-100中能被3整除的数字");
	for (num4 = 1;num4 <= 100;num4++)
	{
		if (num4 % 3 != 0)
		{
			continue;
		}
		printf("%d ", num4);
	}
	printf("\n1-100中既能被5整除，又能被6整除的数字:");

	//case 3 :1-100中，既能被5整除，又能被6整除的数字
	for (int num5 = 1; num5 <= 100; num5++)
	{
		if (num5 % 5 != 0 || num5 % 6 != 0)
		{
			continue;
		}
		printf("%d ", num5);

	}

	return 0;
}