#define _CRT_SECURE_NO_WARNINGS 1

#include "SearchTree.h"

int main()
{
    BSTNode* pRoot;
    InitBSTree(&pRoot);
    int i = 0;
    for (i = 0; i < 5; i++)
    {
        InsertBSTreeNor(&pRoot, i);
    }
    //DestroyBSTree(&pRoot);
    InOrder(pRoot);
    BSTNode* ret = FindBSTreeNor(pRoot, 4);
    printf("\n");
    DelectBSTreeNor(&pRoot, 3);
    InOrder(pRoot);
    printf("\n");
    if (ret)
    {
        printf("该元素在二叉树中\n");
    }
    else
    {
        printf("该元素不在二叉树中\n");
    }

    return 0;
}