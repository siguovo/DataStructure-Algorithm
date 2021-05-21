#pragma once
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 11
#define MinData (-100)

typedef int BHDataType;

typedef struct MinHeap
{
	BHDataType* a;
	int Size;
	int Capacity;
}MinHeap;

//初始化和打印
void MinHeapInit(MinHeap* ph);
void PrintMinHeap(MinHeap* ph);

//最大堆插入一个元素
void MinHeapInsert(MinHeap* ph, BHDataType x);
//删除一般是指删除最大的节点
void MinHeapPopFront(MinHeap* ph);
