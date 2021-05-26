#pragma
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct TreeNode
{
	int value;
	struct TreeNode* Left;
	struct TreeNode* Right;
}TreeNode;

void InOreder(TreeNode* root);
TreeNode* SearchTreeInit();
void SearchTreeDestroy(TreeNode** root);
TreeNode* SearchTreeBuyNode(int data);

TreeNode* SearchTreeInsert(TreeNode* root,int data);
TreeNode* SearchTreeDelete(TreeNode* root, int data);


TreeNode* FindMax(TreeNode* root);
TreeNode* FindMin(TreeNode* root);
TreeNode* Find(TreeNode* root, int data);


