#include "Sort.h"


void Percdown(int* Arr, int parent, int N)
{
	int temp = Arr[parent];
	int child = 2 * parent + 1;
	while (child <= N)
	{
		if (child != N && Arr[child] < Arr[child + 1])
		{
			child++;
		}
		if (temp >= Arr[child]) break;

		Arr[parent] = Arr[child];
		parent = child;
		child = 2 * parent + 1;
	}
	Arr[parent] = temp;
}

void HeapSort(int* Arr, int ArrSize)
{
	//构建大顶堆
	for (int i = (ArrSize - 2) / 2; i >= 0; i--)
	{
		//注意开始位置为0，所以和平常的方法略有不同
		//从0下标开始，父结点对应的子结点为
		//parent = i；
		//child = 2*i+1；
		//逆推当child = ArrSize-1时
		//parent = (ArrSize - 2)/2
		Percdown(Arr, i, ArrSize - 1);
	}
	//交换位置后上浮最大点
	for (int i = ArrSize - 1; i > 0; i--)
	{
		int tmp = Arr[i];
		Arr[i] = Arr[0];
		Arr[0] = tmp;
		Percdown(Arr, 0, i-1);
	}
}
