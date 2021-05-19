#include "Sort.h"

void BubbleSort(int* Arr, int ArrSize)
{
	//每次比较相邻的元素，如果左边的大于右边的，交换。
	//每一次比较完，都会将最大的一个数排到最后面，每次排序都可以少排序一个
	//直到最后不需要交换，设置了一个标志，当没有发生交换的时候，说明已经排序完成
	//可以提前结束，相当于是一个优化
	for (int i = 1; i < ArrSize; i++)
	{
		int flag = 0;
		for (int j = 0; j < ArrSize - i; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				int tmp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = tmp;

				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
