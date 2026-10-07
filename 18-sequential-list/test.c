
//原地移除指定数组中所有数值等于val的元素
//然后返回nums中与val不同的元素的数量
//LeetCode 27
//假设nums中不等于val的元素个数为k，
//更改nums数组，使nums的前k个元素包含不等于val的元素
//返回k
int removeElement(int* nums, int numsSize, int val)
{
	int i = 0;
	int j = 0;
	while (j < numsSize)
	{

		if (nums[j] != val)
		{
			nums[i] = nums[j];
			i++;
		}
		j++;
	}
	return i;
}


//合并两个有序数组

/*
* LeetCode 88
*
给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，
分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。
为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，
后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int i = m - 1;//遍历nums1
	int j = n - 1;//遍历nums2
	int k = nums1Size - 1;//倒着遍历nums1
	while (i >= 0 && j >= 0)
	{
		if (nums1[i] < nums2[j])
		{
			nums1[k] = nums2[j];
			j--;
			//k--;
		}
		else
		{
			nums1[k] = nums1[i];
			//k--;
			i--;
		}
		k--;
	}
	//此时可能出现，nums1已经循环结束，但是nums2还有数据的情况
	while (j >= 0)
	{
		nums1[k--] = nums2[j--];
	}
}






