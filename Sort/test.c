#define  _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
#define N 10

void Print(int* Arr, int ArrSize)
{
	if (ArrSize <= 0)
	{
		printf("NULL!\n");
	}
	for (int i = 0; i < ArrSize; i++)
	{
		printf("%d ", Arr[i]);
	}
	printf("\n");
}





int main() {
	int nums[N] = {0};
	int numsSize = N;
	//3 5 6 8 4 9 15 10 20 11
	//9 8 7 6 5 4 3 2 1 0
	for (int i = 0; i < numsSize; i++) {
		scanf_s("%d", &nums[i]);
	}
	if (numsSize < 2)
	{
		Print(nums, numsSize);
		return 0;
	}

	CountSort(nums, numsSize);
	Print(nums, numsSize);

	MergeSort(nums, numsSize);
	Print(nums, numsSize);

	SelectSort(nums, numsSize);
	Print(nums, numsSize);

	ShellSort(nums, numsSize);
	Print(nums, numsSize);

	QuickSort(nums, numsSize);
	Print(nums, numsSize);

	BubbleSort(nums, numsSize);
	Print(nums, numsSize);

	InsertSort(nums, numsSize);
	Print(nums, numsSize);









	return 0;
}
