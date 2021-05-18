#include "SList.h"


int main()
{
	SListNode* pList = NULL;
	SListPushBack(&pList, 1);	//传地址，双指针解引用
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPrint(&pList);

	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(&pList);

	SListPushFront(&pList, 0);
	SListPushFront(&pList, -1);
	SListPushFront(&pList, -2);
	SListPrint(&pList);


	SListPopFront(&pList);
	SListPrint(&pList);
	SListPopFront(&pList);
	SListPrint(&pList);
	SListPopFront(&pList);
	SListPopFront(&pList);
	SListPrint(&pList);







	return 0;
}