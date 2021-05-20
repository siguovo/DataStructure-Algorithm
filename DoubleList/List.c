#include "List.h"

void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n"); 
}


ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

ListNode* ListInit()
{
	ListNode* phead = BuyListNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}
void ListClear(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	phead->next = phead;
	phead->prev = phead;
}
void ListDestory(ListNode* phead)
{
	assert(phead);
	ListClear(phead);
	free(phead);
}

void ListPushBack(ListNode* phead, LTDataType x)
{
	assert(phead);
	/*ListNode* tail = phead->prev;

	ListNode* newNode = BuyListNode(x);

	tail->next = newNode;
	newNode->prev = tail;

	newNode->next = phead;
	phead->prev = newNode;*/
	ListInsert(phead, x);

}

void ListPopBack(ListNode* phead)
{
	/*assert(phead);
	assert(phead->prev != phead);

	ListNode* tail = phead->prev;
	ListNode* tailPrev = tail->prev;

	phead->prev = tailPrev;
	tailPrev->next = phead;*/

	/*ListNode* tail = phead->prev;
	if (tail == phead)
	{
		printf("no Node!");
		return;
	}
	ListNode* tailprev = tail->prev;
	if (tailprev == phead)
	{
		phead->next = phead;
		phead->prev = phead;
		printf("no Node!");
		free(tail);
	}
	else
	{
		phead->prev = tailprev;
		tailprev->next = phead;
		free(tail);
	}*/
	ListErase(phead->prev);

}

void ListPushFront(ListNode* phead, LTDataType x)
{
	/*assert(phead);
	ListNode* newnode = BuyListNode(x);
	ListNode* first = phead->next;

	phead->next = newnode;
	newnode->prev = phead;

	newnode->next = first;
	first->prev = newnode;*/
	ListInsert(phead->next, x);
}

void ListPopFront(ListNode* phead)
{
	/*assert(phead);
	assert(phead->next != phead);

	ListNode* first = phead->next;
	ListNode* second = first->next;

	phead->next = second;
	second->prev = phead;

	free(first);*/
	ListErase(phead->next);
}

ListNode* ListFind(ListNode* phead, LTDataType x)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur->next != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//ÔÚposÇ°²åÈëx
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* newnode = BuyListNode(x);

	posPrev->next = newnode;
	newnode->prev = posPrev;

	newnode->next = pos;
	pos->prev = newnode;
}
void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	//posPrev  pos  posNext
	posPrev->next = posNext;
	posNext->prev = posPrev;

	free(pos);
}