#define _CRT_SECURE_NO_WARNINGS 1

#include "SearchTree.h"

void InitBSTree(BSTNode** pRoot)
{
    assert(pRoot);
    *pRoot = NULL;
}

BSTNode* BuyBSTNode(BSDataType data)
{
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    if (NULL == newNode)
    {
        printf("创建节点失败\n");
        return NULL;
    }
    newNode->_data = data;
    newNode->_pLeft = NULL;
    newNode->_pRight = NULL;
    return newNode;
}

void InOrder(BSTNode* pRoot)
{
    if (NULL == pRoot)
        return;
    InOrder(pRoot->_pLeft);
    printf("%d ", pRoot->_data);
    InOrder(pRoot->_pRight);
}

bool InsertBSTree(BSTNode** pRoot, BSDataType data)
{
    assert(pRoot);
    if (*pRoot == NULL)
    {
        (*pRoot) = BuyBSTNode(data);
        return true;
    }
    else
    {
        BSTNode* pCur = (*pRoot);
        BSTNode* pParent = NULL;
        //找到插入结点的位置
        while (pCur)
        {
            pParent = pCur;
            if (pCur->_data == data)//如果当前结点=要插入的结点，则退出，因为这个元素已经存在
            {
                return false;
            }
            else if (pCur->_data > data)//如果当前结点数>要插入的数，向当前结点的左子树去找插入位置
            {
                pCur = pCur->_pLeft;
            }
            else//如果当前结点数<要插入的数，向当前结点的右子树去找插入位置
            {
                pCur = pCur->_pRight;
            }
        }
        //插入新结点
        if (data > pParent->_data)//如果插入的元素比它要插入位置的元素大，则要插入的元素应该是要插入位置结点的右孩子
        {
            pParent->_pRight = BuyBSTNode(data);
            return true;
        }
        if (data < pParent->_data)//如果插入的元素比它要插入位置的元素小，则要插入的元素应该是要插入位置结点的左孩子
        {
            pParent->_pLeft = BuyBSTNode(data);
            return true;
        }
    }
    return false;
}

bool DelectBSTree(BSTNode** pRoot, BSDataType data)
{
    assert(pRoot);
    BSTNode* pCur = NULL;
    BSTNode* pParent = NULL;
    if (NULL == *pRoot)
        return false;
    else
    {
        //找到待删除结点

        pCur = *pRoot;
        while (pCur)
        {
            if (data > pCur->_data)
            {
                pParent = pCur;
                pCur = pCur->_pRight;
            }
            else if (data < pCur->_data)
            {
                pParent = pCur;
                pCur = pCur->_pLeft;
            }
            else
                break;
        }
        //删除结点

        //待删结点是叶子节点或者只有右孩子
        if (NULL == pCur->_pLeft)
        {
            if (pCur == *pRoot)//若果删除的是根结点
                *pRoot = pCur->_pRight;
            else if (pCur == pParent->_pLeft)
                pParent->_pLeft = pCur->_pRight;
            else
                pParent->_pRight = pCur->_pRight;
        }
        //只有左孩子
        else if (NULL == pCur->_pRight)
        {
            if (pCur == *pRoot)//若果删除的是根结点
                *pRoot = pCur->_pLeft;
            else if (pCur == pParent->_pLeft)
                pParent->_pLeft = pCur->_pLeft;
            else
                pParent->_pRight = pCur->_pLeft;
        }
        //左右孩子都存在
        else
        {
            //替代法，向待删除点的右子树找最左边的数（最小）/向待删除点的左子树找最右边的数（最大），将待删除点与最左边/最右边的数交换，删除最左边/最右边的数
            BSTNode* Inorder = pCur->_pRight;

            while (Inorder->_pLeft)//除了循环函数，Inorder不可能有左孩子
            {
                pParent = Inorder;
                Inorder = Inorder->_pLeft;
            }
            pCur->_data = Inorder->_data;//交换
            if (Inorder == pParent->_pLeft)
                pParent->_pLeft = Inorder->_pRight;
            else if (Inorder == pParent->_pRight)
                pParent->_pRight = Inorder->_pRight;
            pCur = Inorder;
        }
    }
    free(pCur);
    pCur = NULL;
    return true;
}

BSTNode* FindBSTree(BSTNode* pRoot, BSDataType data)
{
    BSTNode* pCur = NULL;
    if (NULL == pRoot)
        return NULL;

    pCur = pRoot;
    while (pCur)
    {
        if (pCur->_data == data)
        {
            return pCur;
        }
        else if (pCur->_data > data)
        {
            pCur = pCur->_pLeft;
        }
        else
        {
            pCur = pCur->_pRight;
        }
    }
    return NULL;
}

void DestroyBSTree(BSTNode** pRoot)
{
    assert(pRoot);
    if (*pRoot)
    {
        DestroyBSTree(&(*pRoot)->_pLeft);
        DestroyBSTree(&(*pRoot)->_pRight);
        free(*pRoot);
        *pRoot = NULL;
    }
}

BSTNode* FindBSTreeNor(BSTNode* pRoot, BSDataType data)
{
    if (NULL == pRoot)
        return NULL;
    else if (data == pRoot->_data)
        return pRoot;
    else if (data < pRoot->_data)
        return FindBSTreeNor(pRoot->_pLeft, data);
    else
        return FindBSTreeNor(pRoot->_pRight, data);
}

bool InsertBSTreeNor(BSTNode** pRoot, BSDataType data)
{
    assert(pRoot);
    if (NULL == *pRoot)
        *pRoot = BuyBSTNode(data);
    else
    {
        if (data == (*pRoot)->_data)
        {
            return false;
        }
        else if (data < (*pRoot)->_data)
            return InsertBSTree(&(*pRoot)->_pLeft, data);
        else
            return InsertBSTree(&(*pRoot)->_pRight, data);

    }
    return true;
}

bool DelectBSTreeNor(BSTNode** pRoot, BSDataType data)
{
    assert(pRoot);

    if (NULL == *pRoot)
        return false;
    else
    {

        if (data > (*pRoot)->_data)
        {
            return DelectBSTreeNor(&(*pRoot)->_pRight, data);
        }
        else if (data < (*pRoot)->_data)
        {
            return DelectBSTreeNor(&(*pRoot)->_pLeft, data);
        }
        else //data == (*pRoot)->_data
        {
            //这时已经找到了待删除结点
            BSTNode* pDel = *pRoot;
            if (NULL == pDel->_pLeft)
            {
                *pRoot = pDel->_pRight;
                free(pDel);
                return true;
            }
            else if (NULL == (*pRoot)->_pRight)
            {
                *pRoot = pDel->_pLeft;
                free(pDel);
                return true;
            }
            else //左右孩子都存在
            {
                BSTNode* Inorder = pDel->_pRight;
                while (Inorder->_pLeft)
                    Inorder = Inorder->_pLeft;
                pDel->_data = Inorder->_data;
                return DelectBSTreeNor(&(*pRoot)->_pRight, pDel->_data);
            }
        }
    }
}