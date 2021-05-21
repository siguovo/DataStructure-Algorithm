#include "MaxHeap.h"


void PrintMaxHeap(MaxHeap* ph)
{
	if (ph->Size == 0)
	{
		printf("no element");
		return;
	}
	for (int i = 1; i <= ph->Size; i++)
	{
		printf("%d ", ph->a[i]);
	}
	printf("\n");
}


void MaxHeapInit(MaxHeap* ph)
{
	ph->a = malloc(sizeof(BHDataType) * MaxSize);
	if (ph->a == NULL)
	{
		printf("malloc error!");
		//exit(-1);
		return;
	}
	ph->Size = 0;
	ph->Capacity = MaxSize;
	ph->a[0] = MaxData;
}


void MaxHeapInsert(MaxHeap* ph, BHDataType x)
{
	if (ph->Size == ph->Capacity)
	{
		printf("is full! ");
		exit(-1);
		//return;
	}
	int i = ++ph->Size;
	for ( ; ph->a[i / 2] < x; i /= 2)
	{
		ph->a[i] = ph->a[i / 2];
	}
	ph->a[i] = x;
}

void MaxHeapPopFront(MaxHeap* ph)
{
	//如果长度为0，表明堆中没有元素
	if (ph->Size == 0)
	{
		printf("is Empty!");
		return;
	}
	//找到堆的最后一个元素
	int end = ph->Size;
	//将最后一个元素替换到头部
	ph->a[1] = ph->a[end];
	//记录这个元素为最大值
	BHDataType Max = ph->a[1];
	//声明一个孩子结点
	int i, child;
	//从1开始遍历，保证有孩子结点，下一次从孩子结点遍历
	for (i = 1; 2 * i <= ph->Size; i = child)
	{
		//堆的左孩子为他的下标的两倍
		child = 2 * i;
		//如果左孩子不是最后一个元素，说明他还有右孩子，选两个孩子中较大的一个
		if (child != ph->Size && ph->a[child] < ph->a[child + 1])
		{
			child++;
		}//如果孩子结点都比他小，根据最大堆性质，可以确定该结点就是当前堆的最大值
		if (Max >= ph->a[child])
		{
			break;
		}
		//如果孩子结点大于他，让子节点往上走
		else
		{
			ph->a[i] = ph->a[child];
		}
	}
	ph->a[i] = Max;
	ph->Size--;
}
