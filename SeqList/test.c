#include "SeqList.h"


//测试头尾的插入和删除
void TestSeqList1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);


	SeqListPushFront(&s, -1);
	SeqListPushFront(&s, -2);
	SeqListPushFront(&s, -3);
	SeqListPrint(&s);


	SeqListPopFront(&s);
	SeqListPopFront(&s);
	SeqListPrint(&s);
	

	
	SeqListInsert(&s, 0, 8);
	SeqListInsert(&s, 8, 0);
	SeqListInsert(&s, 5, -2);
	//SeqListInsert(&s, 10, 0);//测试超过数组长度
	SeqListPrint(&s);
	


	SeqListErase(&s, 0);
	SeqListPrint(&s);
	SeqListErase(&s, 5);
	SeqListPrint(&s);
	SeqListErase(&s, 1);
	SeqListPrint(&s);


	int i;
	i=SeqListFind(&s, 50);
	printf("%d\n", i);
	i = SeqListFind(&s, 5);
	printf("%d\n", i);
	i = SeqListFind(&s, -1);
	printf("%d\n", i);

	SeqListSort(&s);
	SeqListPrint(&s);


	int j;
	j = SeqListBubaryFind(&s, 4);
	printf("%d\n", j);
}


int main()
{
	TestSeqList1();

	//TestSeqList2();


	return 0;
}