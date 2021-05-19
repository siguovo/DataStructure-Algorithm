#include "Sort.h"

void ShellSort(int* Arr, int ArrSize)
{
	int step = ArrSize / 2;
	//step不能等于0，不然会无限循环
	for (step; step > 0; step /= 2)
	{
		for (int i = step; i < ArrSize; i++)
		{
			int j = i;
			int temp = Arr[j];
			while (j - step >= 0 && Arr[j - step] > temp)
			{
				Arr[j] = Arr[j - step];
				j = j - step;
			}
			Arr[j] = temp;
		}
	}
}
/*找步长，分组，跟对应位置的数比较，进行插入排序，
*最后当步长为1时，相邻两个比较，排完顺序
*/