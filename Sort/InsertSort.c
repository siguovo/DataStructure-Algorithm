#include "Sort.h"

void InsertSort(int* Arr, int ArrSize)
{
	//for循环固定n次，while循环最坏情况下((n-1)+(n-2)+...+(1))=n/2
	//时间复杂度为n*(n/2)------->O(n^2)
	//空间复杂度为O(1)
	for (int i = 1; i < ArrSize; i++)
	{
		int tmp = Arr[i];
		int j = i;
		while (j > 0 && Arr[j - 1] > tmp)
		{
			Arr[j] = Arr[j - 1];
			j--;
		}
		if (j != i)
		{
			Arr[j] = tmp;
		}
	}
}
