#include "rbtree.h"
#include <iostream>
using namespace std;
//叶子节点默认值
Node nil(-1);
Node* NIL = &nil;
//结点的构造函数
Node::Node(int k) : key(k)
{
	p = left = right = NIL;
	color = BLACK;
}
//rbtree构造函数
RBTree::RBTree(Node* n) :root(n) 
{
	n->left = n->right = n->p = NIL;
}
//中序遍历打印
void RBTree::InorderTreeWalk(Node* n)
{
	if (n == NIL)
		return;
	InorderTreeWalk(n->left);
	cout << n->key << ' ';
	InorderTreeWalk(n->right);
}
//右旋
void RBTree::RightRotate(Node* n)
{
	if (n == root)//判断该节点是否为根节点
		root = n->left;

	Node* temp = n->left;

	n->left = temp->right;
	temp->right->p = n;

	temp->right = n;
	temp->p = n->p;
	if (n == n->p->left)
		n->p->left = temp;
	else
		n->p->right = temp;

	n->p = temp;
}
//左旋
void RBTree::LeftRotate(Node* n)
{
	if (n == root)
		root = n->right;

	Node* temp = n->right;

	n->right = temp->left;
	temp->left->p = n;

	temp->left = n;
	temp->p = n->p;
	if (n == n->p->left)
		n->p->left = temp;
	else
		n->p->right = temp;

	n->p = temp;
}
//查找
Node* RBTree::Search(int k)
{
	Node* cur = root;
	
	while (cur->key != k)
	{
		//left
		if (k < cur->key && cur->left != NIL)
		{
			cur = cur->left;
		}//right
		else if (k > cur->key && cur->right != NIL)
		{
			cur = cur->right;
		}//no found
		else
			return NIL;
	}//找到
	return cur;
}
//插入
Node* RBTree::Insert(int k)
{
	Node* cur = root;//用来遍历
	Node* prev = root;//保存插入值的父结点
	while (cur != NIL)//找到要插入的位置(一般都是在最尾部插入)
	{
		prev = cur;
		if (k < cur->key)
		{
			cur = cur->left;
		}
		else if (k > cur->key)
		{
			cur = cur->right;
		}
		else
		{
			cout << k << " already in rbtree." << endl;
			return NIL;//存在直接返回NIL
		}
	}
	if (k < prev->key)//往左边插入
	{
		prev->left = new Node(k);
		prev->left->p = prev;
		prev->left->left = prev->left->right = NIL;
		prev->left->color = RED;//新插入的节点默认为红色
		//插入后要进行颜色检查，保证红黑树的特性
		InsertFixup(prev->left);
		return prev->left;//返回的都是插入的节点
	}
	else if (k > prev->key)
	{
		prev->right = new Node(k);
		prev->right->p = prev;
		prev->right->left = prev->right->right = NIL;
		prev->right->color = RED;
		InsertFixup(prev->right);
		return prev->right;
	}
}
//插入后变色
void RBTree::InsertFixup(Node* s)
{
	while (s->p->color == RED)//只有父结点为红色我们才需要调整颜色
	{
		if (s->p == s->p->p->left)//父红且为左 red and left
		{
			Node* u = s->p->p->right;//u -->uncle  p-->parent  g-->grandparent
			if (u->color == RED)//u p 都为红 ---->u p 变黑，g 变红 -->OK
			{
				s->p->color = u->color = BLACK;
				s = s->p->p;//向上去查看上面的颜色是否冲突
			}
			else if (u->color == BLACK && s == s->p->left)//g p s 左左左 and 黑红红
			{
				//p 变黑 g 变红---->g右旋--->OK
				s->p->color = BLACK;
				s->p->p->color = RED;
				RightRotate(s->p->p);
			}
			else if (u->color == BLACK && s == s->p->right)//g p s 左左右 and 黑红红
			{
				// p 左旋(g s p 左左左上面的情形) --> g 变红 s 变黑 -->g 右旋(while循环会帮我们调用)
				s = s->p;
				LeftRotate(s);
			}
		}
		else if (s->p == s->p->p->right)
		{
			Node* u = s->p->p->left;
			if (u->color == RED)
			{
				s->p->color = u->color = BLACK;
				s->p->p->color = RED;
				s = s->p->p;
			}
			else if (u->color == BLACK && s == s->p->right)
			{
				s->p->color = BLACK;
				s->p->p->color = RED;
				LeftRotate(s->p->p);
			}
			else if (u->color == BLACK && s == s->p->left)
			{
				s = s->p;
				RightRotate(s);
			}
		}
	}
	root->color = BLACK;//不管你如何转换颜色，最后到根节点的颜色始终为黑色
}
//删除
bool RBTree::Delete(int k)
{
	Node* toDelete = Search(k);
	if (toDelete == NIL)//没有要删除的值，返回false
	{
		return false;
	}
	Node* toRepleace = toDelete;
	ColorType Delete_color = toDelete->color;
	Node* Flag;
	if (toDelete->left == NIL)//左孩子空
	{
		Flag = toDelete->right;
		TransPlant(toDelete, toDelete->right);
	}
	else if (toDelete->right == NIL)//右孩子空
	{
		Flag = toDelete->left;
		TransPlant(toDelete, toDelete->left);
	}
	else//中间位置
	{
		toRepleace = Successor(toDelete);//找右子树最小值来替换
		Flag = toRepleace->right;//保存的真正被删除的节点的位置
		Delete_color = toRepleace->color;
		if (toRepleace->p == toDelete)//最小值刚好是delete的右子树
		{
			TransPlant(toDelete, toRepleace);
			toRepleace->left = toDelete->left;
			toDelete->left->p = toRepleace;
			toRepleace->color = toDelete->color;
		}
		else
		{
			//找到最小值，先把最小值的右子树对接好
			TransPlant(toRepleace, toRepleace->right);
			//把最小值换入删除的节点位置
			toRepleace->left = toDelete->left;
			toDelete->left->p = toRepleace;
			toRepleace->right = toDelete->right;
			toDelete->right->p = toRepleace;
			TransPlant(toDelete, toRepleace);
		}
	}
	if (Delete_color == BLACK)//删除节点是黑色，就要调整颜色
		DeleteFixup(Flag);
	return true;
}
//删除后变色
void RBTree::DeleteFixup(Node* n)
{
	while (n->color == BLACK && n != root)
	{
		if (n == n->p->left)
		{
			Node* bother = n->p->right;
			if (bother->color == RED)
			{
				n->p->color = RED;
				bother->color = BLACK;
				LeftRotate(n->p);
				bother = n->p->right;
			}
			else if (bother->left->color == BLACK && bother->right->color == BLACK)
			{
				n->p->color = RED;
				n = n->p;
			}
			else if (bother->color == BLACK && bother->left->color == RED)
			{
				bother->color = RED;
				bother->left->color = BLACK;
				RightRotate(bother);
			}
			else if (bother->right->color == RED)
			{

				bother->right->color = BLACK;
				bother->color = n->p->color;
				n->p->color = BLACK;
				LeftRotate(n->p);
				n = root;
			}
		}
		else if (n = n->p->right)
		{
			Node* bother = n->p->left;
			if (bother->color == RED)
			{
				n->p->color = RED;
				bother->color = BLACK;
				RightRotate(n->p);
				bother = n->p->left;
			}
			else if (bother->left->color == BLACK && bother->right->color == BLACK)
			{
				n->p->color = RED;
				n = n->p;
			}
			else if (bother->color == BLACK && bother->right->color == RED)
			{
				bother->color = RED;
				bother->right->color = BLACK;
				LeftRotate(bother);
			}
			else if (bother->left->color == RED)
			{
				bother->left->color = BLACK;
				bother->color = n->p->color;
				n->p->color = BLACK;
				RightRotate(n->p);
				n = root;
			}
		}
	}
	n->color = BLACK;
}
//找右子树最小值替换删除节点
Node* RBTree::Successor(Node* n)
{
	Node* cur = n;
	if (cur->right != NIL)
	{
		return RBTree(cur->right).Minnum();
	}
	else if (cur->p != NIL)
	{
		return cur->p;
	}
	else return NIL;
}
//树中的最大值
Node* RBTree::Minnum()
{
	Node* cur = root;
	while (cur->left != NIL)
		cur = cur->left;
	return cur;
}
//树中的最小值
Node* RBTree::Maxnum()
{
	Node* cur = root;
	while (cur->right != NIL)
		cur = cur->right;
	return cur;
}
//将n2连接到n1的父结点上面
void RBTree::TransPlant(Node* n1, Node* n2)
{
	n2->p = n1->p;
	if (n1 == n1->p->left)//左
	{
		n1->p->left = n2;
	}
	else if(n1 == n1->p->right)//右
	{
		n1->p->right = n2;
	}
	else//根
		root = n2;
}
