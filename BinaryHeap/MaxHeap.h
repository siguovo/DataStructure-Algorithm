#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 11
#define MaxData 100

typedef int BHDataType;

typedef struct MaxHeap
{
	BHDataType* a;
	int Size;
	int Capacity;
}MaxHeap;

//初始化和打印
void MaxHeapInit(MaxHeap* ph);
void PrintMaxHeap(MaxHeap* ph);

//最大堆插入一个元素
void MaxHeapInsert(MaxHeap* ph, BHDataType x);
//删除一般是指删除最大的节点
void MaxHeapPopFront(MaxHeap* ph);
