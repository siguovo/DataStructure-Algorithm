#include "Sort.h"

int partition(int* Arr, int left, int right)
{
	int pivot = Arr[left];
	int i = left;
	int j = right;
	while (i < j)
	{
		while (i < j && Arr[j] >= pivot)
		{
			j--;
		}
		//ps：找到后面有一个值比基准值还小的话，就把这个值放到左边去
		Arr[i] = Arr[j];
		while (i < j && Arr[i] <= pivot)
		{
			i++;
		}
		//找到前面有一个值比基准值大的话，就把这个值放到后面去，最后知道i，j相遇循环终止
		Arr[j] = Arr[i];
	}
	Arr[i] = pivot;
	return i;
}

void QSort(int* Arr, int left, int right)
{
	if (left < right)
	{
		//找基准位置，每次找到的基准位置都已经被排序好了，因为基准位置的左边比他小，右边比他大，
		//所以递归时就不用在排基准位置了，相当于每次排序完之后基准位置都被排好了，递归最后终止
		int mid = partition(Arr, left, right);
		QSort(Arr, left, mid - 1);
		QSort(Arr, mid + 1, right);
	}
}
/*快排的基本思想就是选择一个基准位置，将比这个基准位置小的数放到他的左边，
**比这个位置大的数放到右边，递归的将所有元素排序完成*/
void QuickSort(int* Arr, int ArrSize)
{
	QSort(Arr, 0, ArrSize - 1);
}

