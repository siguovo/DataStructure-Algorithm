#include "AvlTree.h"


void AvlTreeInit(AvlNode** root)
{
	assert(*root);
	*root = NULL;
}

static int Height(AvlNode* root)
{
	if (NULL == root)
	{
		return -1;
	}
	else
	{
		return root->Height;
	}
}



AvlNode* AvlTreeInsert(AvlNode* root, int data)
{
	if (NULL == root)
	{
		root = (AvlNode*)malloc(sizeof(AvlNode));
		if (NULL == root)
		{
			exit(-1);
		}
		root->value = data;
		root->Left = root->Right = NULL;
		root->Height = 0;
	}
	else if (data < root->value)
	{
		root->Left = AvlTreeInsert(root->Left, data);
		//在左边插入 L
		if (Height(root->Left) - Height(root->Right) == 2)
		{
			//插入到左子树的左子树 L
			if (data < root->Left->value)  //LL
			{
				//执行一次单旋转
				root = SingleRotateWithLeft(root);
			}
			else   //LR
			{
				//双旋转 
				root = DoubleRotateWithLeft(root);
			}
		}
	}
	else if (data > root->value)
	{
		root->Right = AvlTreeInsert(root->Right, data);
		//在右边插入 R
		if (Height(root->Right) - Height(root->Left) == 2)
		{
			//插入到右子树的左子树 L
			if (data < root->Right->value)  //RL
			{
				//双旋转 
				root = DoubleRotateWithRight(root);
			}
			else   //RR
			{
				//执行一次单旋转
				root = SingleRotateWithRight(root);
			}
		}
	}
	//更新最后根节点的高度
	root->Height = fmax(Height(root->Left), Height(root->Right)) + 1;
	return root;
}

//单次左旋转 LL
AvlNode* SingleRotateWithLeft(AvlNode* P)
{
	//P  是指Parent   S   是指Son
	AvlNode* S;
	S = P->Left;
	//单旋转 1. P结点的左节点位置  指向  S节点的右节点
	//2. 让S节点空出来的右子节点  连接到  P节点
	P->Left = S->Right;
	S->Right = P;

	//更新高度
	P->Height = fmax(Height(P->Left), Height(P->Right)) + 1;
	S->Height = fmax(Height(S->Left), Height(S->Right)) + 1;

	//返回S表示 S是祖父节点的子节点
	return S;
}
//单次右旋转 RR
AvlNode* SingleRotateWithRight(AvlNode* P)
{

	AvlNode* S;
	S = P->Right;
	//单旋转 1. P结点的右节点位置  指向  S节点的左节点
	//2. 让S节点空出来的左子节点  连接到  P节点
	P->Right = S->Left;
	S->Left = P;

	//更新高度
	P->Height = fmax(Height(P->Left), Height(P->Right)) + 1;
	S->Height = fmax(Height(S->Left), Height(S->Right)) + 1;

	//返回S表示 S是祖父节点的子节点
	return S;
}

//左子树两次旋转LR
AvlNode* DoubleRotateWithLeft(AvlNode* G)
{
	//首先对祖父节点（G节点）的子节点（P节点）进行一次右旋转
	G->Left = SingleRotateWithRight(G->Left);//R
	//然后再对祖父节点进行一次左旋转
	return SingleRotateWithLeft(G);//L
}

//右子树两次旋转RL
AvlNode* DoubleRotateWithRight(AvlNode* G)
{
	//首先对祖父节点（G节点）的子节点（P节点）进行一次右旋转
	G->Right = SingleRotateWithLeft(G->Right);//L
	//然后再对祖父节点进行一次左旋转
	return SingleRotateWithRight(G); //R
}