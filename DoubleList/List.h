#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType data;
}ListNode;


ListNode* ListInit(); 
//清除所有数据
void ListClear(ListNode* phead);
//销毁包括头结点
void ListDestory(ListNode* phead);
ListNode* BuyListNode(LTDataType x);
void ListPrint(ListNode* phead);
//尾插尾删
void ListPushBack(ListNode* phead, LTDataType x);
void ListPopBack(ListNode* phead);
//头插头删
void ListPushFront(ListNode* phead, LTDataType x);
void ListPopFront(ListNode* phead);

ListNode* ListFind(ListNode* phead, LTDataType x);
//在pos前插入x
void ListInsert(ListNode* pos, LTDataType x);
void ListErase(ListNode* pos);


