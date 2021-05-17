#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//顺序表，有效数组在数组中必须是连续
//静态顺序表设计（固定大小）
//实现动态顺序表
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* a;	//指向动态开辟的数组
	int size;		//有效数据的大小
	int capacity;	//容量空间的大小
}SL,SeqList;


void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListCheckCaapacity(SL* ps);

//尾插尾删，头插头删
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPopFront(SL* ps);
//任意位置的插入删除
void SeqListInsert(SL* ps, int pos, SLDataType x);
void SeqListErase(SL* ps, int pos);
//查找  二分查找
int SeqListFind(SL* ps, SLDataType x);

//排序
void SeqListSort(SL* ps);

//排序后进行二分查找
int SeqListBubaryFind(SL* ps, SLDataType x);
