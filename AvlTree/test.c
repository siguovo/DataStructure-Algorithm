#include "AvlTree.h"


void test01()
{
	AvlNode* root;
	AvlTreeInit(&root);
	root = AvlTreeInsert(root, 5);
	root = AvlTreeInsert(root, 7);
	root = AvlTreeInsert(root, 8);
	root = AvlTreeInsert(root, 1);
	root = AvlTreeInsert(root, 2);
	root = AvlTreeInsert(root, 9);





}



int main()
{
	test01();


	return 0;
}