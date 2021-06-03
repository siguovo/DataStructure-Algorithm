#pragma once

typedef enum c { RED, BLACK } ColorType;

class Node
{
public:
	Node(int k);

	int key;
	Node* p;
	Node* left;
	Node* right;
	ColorType color;
};

class RBTree
{
public:
	explicit RBTree(Node* n);
	void InorderTreeWalk(Node* n);
	Node* Search(int k);
	Node* Insert(int k);
	Node* Minnum();
	Node* Maxnum();
	Node* Successor(Node* n);
	bool Delete(int k);


	Node* root;
private:
	void InsertFixup(Node* s);
	void RightRotate(Node* n);
	void LeftRotate(Node* n);
	void TransPlant(Node* n1, Node* n2);
	void DeleteFixup(Node* n);
};