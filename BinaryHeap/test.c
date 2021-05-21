#include "MinHeap.h"
#include "MaxHeap.h"

void TestHeap1()
{
	MaxHeap h;
	MaxHeapInit(&h);

	MaxHeapInsert(&h, 1);
	MaxHeapInsert(&h, 2);
	MaxHeapInsert(&h, 3);
	MaxHeapInsert(&h, 4);
	MaxHeapInsert(&h, 5);
	MaxHeapInsert(&h, 6);
	MaxHeapInsert(&h, 7);
	MaxHeapInsert(&h, 8);
	MaxHeapInsert(&h, 9);
	PrintMaxHeap(&h);

	MaxHeapPopFront(&h);
	MaxHeapPopFront(&h);

	PrintMaxHeap(&h);


}

void TestHeap2()
{
	MinHeap h;
	MinHeapInit(&h);

	MinHeapInsert(&h, 1);
	MinHeapInsert(&h, 2);
	MinHeapInsert(&h, 3);
	MinHeapInsert(&h, 4);
	MinHeapInsert(&h, 5);
	MinHeapInsert(&h, 6);
	MinHeapInsert(&h, 7);
	MinHeapInsert(&h, 8);
	MinHeapInsert(&h, 9);
	PrintMinHeap(&h);

	MinHeapPopFront(&h);
	MinHeapPopFront(&h);

	PrintMinHeap(&h);

}



int main()
{
	TestHeap1();
	TestHeap2();


	return 0;
}