#include "Sort.h"

void SelectSort(int* Arr, int ArrSize)
{
	for (int i = 0; i < ArrSize; i++)
	{
		int min = i;
		for (int j = i; j < ArrSize; j++)
		{
			if (Arr[j] < Arr[min])
			{
				
				min = j;
			}
		}
		if (i != min)
		{
			int temp = Arr[i];
			Arr[i] = Arr[min];
			Arr[min] = temp;
		}
	}
}
