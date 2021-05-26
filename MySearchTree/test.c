#include "SearchTree.h"



void test01()
{
	TreeNode* root;
	root = SearchTreeInit();
	root = SearchTreeInsert(root, 5);
	root = SearchTreeInsert(root, 4);
	root = SearchTreeInsert(root, 6);
	InOreder(root);
	printf("\n");

	/*TreeNode* max;
	max = FindMax(root);
	TreeNode* min;
	min = FindMin(root);*/

	/*TreeNode* find7;
	find7 = Find(root, 7);*/

	root = SearchTreeDelete(root, 5);
	InOreder(root);
	printf("\n");

	//SearchTreeDestroy(&root);
	InOreder(root);
	printf("\n");

}


int main()
{
	
	test01();



	return 0;
}

