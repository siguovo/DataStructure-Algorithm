#include "Sort.h"


void CSort(int* A, int ASize, int K)
{
	//临时存储A中的排好数据
	int* B = (int*)calloc(ASize, sizeof(int));
	//计数A中元素的个数
	int* C = (int*)calloc(K, sizeof(int));
	//计数，A中每个元素的个数,记录在C中
	for (int i = 0; i < ASize; i++)
	{
		C[A[i]] = C[A[i]] + 1;
	}
	//计算相对偏移量,
	for (int i = 1; i < K; i++)
	{
		C[i] = C[i] + C[i - 1];
	}
	//用B来暂时保存排序好的数
	for (int i = ASize - 1; i >= 0; i--)
	{
		B[C[A[i]] - 1] = A[i];
		C[A[i]] = C[A[i]] - 1;
	}
	//将B中排好序的数，按顺序传给A
	for (int i = 0; i < ASize; i++)
	{
		A[i] = B[i];
	}

	free(C);
	free(B);
}

void CountSort(int* Arr, int ArrSize)
{
	//找到数组中的最大值，方便给C数组分配空间
	int max = Arr[0];
	for (int i = 0; i < ArrSize; i++)
	{
		if (Arr[i] >= max)
		{
			max = Arr[i];
		}
	}
	CSort(Arr, ArrSize, max + 1);
}
