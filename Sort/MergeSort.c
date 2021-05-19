#include "Sort.h"


void Merge(int* Arr, int left, int mid, int right)
{
	int* res = (int*)malloc(sizeof(int) * (right - left + 1));
	int index = 0;
	int front = left;
	int rear = mid + 1;

	while (front <= mid && rear <= right)
	{
		if (Arr[front] < Arr[rear])
		{
			res[index] = Arr[front];
			front++;
			index++;
		}
		else
		{
			res[index] = Arr[rear];
			rear++;
			index++;
		}
	}
	while (front <= mid)
	{
		res[index] = Arr[front];
		front++;
		index++;
	}
	while (rear <= right)
	{
		res[index] = Arr[rear];
		rear++;
		index++;
	}

	int j = 0;
	for (int i = left; i <= right; i++)
	{
		Arr[i] = res[j++];
	}
	free(res);
}

void MSort(int* Arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MSort(Arr, left, mid);
		MSort(Arr, mid + 1, right);
		Merge(Arr, left, mid, right);
	}
}

void MergeSort(int* Arr, int ArrSize)
{
	MSort(Arr, 0, ArrSize - 1);
}
