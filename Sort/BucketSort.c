#include "Sort.h"


void BucketSort(int* Arr, int ArrSize)
{
	int max = Arr[0];
	for (int i = 1; i < ArrSize; i++)
	{
		if (max < Arr[i])
		{
			max = Arr[i];
		}
	}
	
	int* bucket = (int*)calloc(max + 1, sizeof(int));
	for (int i = 0; i < ArrSize; i++)
	{
		bucket[Arr[i]]++;
	}
	int j = 0;
	for (int i = 0; i < max + 1; i++)
	{
		while ((bucket[i]--) > 0)
		{
			Arr[j++] = i;
		}
	}
}
