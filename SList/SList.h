#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef int SListDataType;

typedef struct SListNode
{
	SListDataType data;
	struct SListNode* next;
}SListNode;

SListNode* BuySListNode(SListDataType x);
void SListPrint(SListNode** pphead);

//尾插尾删
void SListPushBack(SListNode** pphead, SListDataType x);
void SListPopBack(SListNode** pphead);
//头插头删
void SListPushFront(SListNode** pphead, SListDataType x);
void SListPopFront(SListNode** pphead);

//中间插入删除
