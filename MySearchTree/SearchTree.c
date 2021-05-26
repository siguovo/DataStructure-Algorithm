#include "SearchTree.h"

TreeNode* SearchTreeInit()
{
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	if (NULL == root)
	{
		exit(-1);
	}
	root = NULL;
	return root;
}
TreeNode* SearchTreeBuyNode(int data)
{
	TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
	if (NULL == newnode)
	{
		exit(-1);
	}
	newnode->value = data;
	newnode->Left = newnode->Right = NULL;

	return newnode;
}


TreeNode* SearchTreeInsert(TreeNode* root, int data)
{
	if (root == NULL)
	{
		root = SearchTreeBuyNode(data);
	}
 	else if (data < root->value)
	{
		root->Left = SearchTreeInsert(root->Left, data);
	}
	else if (data > root->value)
	{
		root->Right = SearchTreeInsert(root->Right, data);
	}

	return root;
}
//非递归实现找最大值
TreeNode* FindMax(TreeNode* root)
{
	if (root != NULL)
	{
		while (root->Right != NULL)
		{
			root = root->Right;
		}
	}
	return root;
}
//递归实现找最小值
TreeNode* FindMin(TreeNode* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (root->Left == NULL)
	{
		return root;
	}
	else
		return FindMin(root->Left);
}

TreeNode* Find(TreeNode* root, int data)
{
	if (root == NULL)
	{
		return NULL;
	}
	else if (data < root->value)
	{
		return Find(root->Left,data);
	}
	else if (data > root->value)
	{
		return Find(root->Right, data);
	}
	else 
		return root;
}
//删除要分情况讨论
//1.没有节点 2.大于根节点 3.小于根节点 4.要删除的节点有一个子节点 5.要删除的节点有两节点
TreeNode* SearchTreeDelete(TreeNode* root, int data)
{
	TreeNode* temp;
	if (root == NULL)
	{
		return NULL;
	}
	else if (data < root->value)
	{
		root->Left = SearchTreeDelete(root->Left, data);
	}
	else if (data > root->value)
	{
		root->Right = SearchTreeDelete(root->Right, data);
	}
	else if (root->Left && root->Right)
	{
		temp = FindMin(root->Right);
		root->value = temp->value;
		root->Right = SearchTreeDelete(root->Right, temp->value);
	}
	else
	{
		temp = root;
		if (root->Left == NULL)
		{
			root = root->Right;
		}
		else if (root->Right == NULL)
		{
			root = root->Left;
		}
		free(temp);
	}
	return root;
}

void SearchTreeDestroy(TreeNode** root)
{
	if (*root)
	{
		SearchTreeDestroy(&(*root)->Left);
		SearchTreeDestroy(&(*root)->Right);
		free(*root);
		*root = NULL;
	}
}

void InOreder(TreeNode* root)
{
	if (root == NULL)
	{
		return;
	}
	InOreder(root->Left);
	printf("%d ", root->value);
	InOreder(root->Right);
}
