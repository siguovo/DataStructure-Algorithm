#include "rbtree.h"
#include <iostream>
using namespace std;



void test()
{
	Node* root = new Node(99);
	RBTree tree(root);
	tree.Insert(80);
	tree.Insert(90);
	tree.Insert(100);
	tree.Insert(110);
	tree.Insert(120);
	tree.Insert(60);
	tree.InorderTreeWalk(tree.root);
	cout << endl;
	tree.Delete(120);


	tree.InorderTreeWalk(tree.root);

	cout << endl;
	cout << tree.Maxnum()->key << ' ' << tree.Minnum()->key << endl;
}






int main()
{
	test();
	system("pause");
	return 0;
}