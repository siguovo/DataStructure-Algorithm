#pragma
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>


typedef struct AvlNode
{
	int value;
	struct AvlNode* Left;
	struct AvlNode* Right;
	int Height;
}AvlNode;

void AvlTreeInit(AvlNode** root);
static int Height(AvlNode* root);

AvlNode* AvlTreeInsert(AvlNode* root, int data);

AvlNode* SingleRotateWithLeft(AvlNode* P);
AvlNode* SingleRotateWithRight(AvlNode* P);
AvlNode* DoubleRotateWithLeft(AvlNode* G);
AvlNode* DoubleRotateWithRight(AvlNode* G);