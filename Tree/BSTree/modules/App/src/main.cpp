#include "BSTree.hpp"

int main()
{
	BSTree<int, int> bst;
	bst.Insert(5, 1);
	bst.Insert(3, 1);
	bst.Insert(4, 1);
	bst.Insert(1, 1);
	bst.Insert(7, 1);
	bst.Insert(8, 1);
	bst.Insert(2, 1);
	bst.Insert(6, 1);
	bst.Insert(0, 1);
	bst.Insert(9, 1);
	bst.Inorder();
	std::cout << bst.Height(bst.root) << std::endl;
	bst.Remove(7);
	bst.Inorder();	
	bst.Remove(0);
	bst.Inorder();
	bst.Remove(9);
	bst.Inorder();
	bst.Remove(1);
	bst.Inorder();
	bst.Remove(5);
	bst.Inorder();
	bst.Remove(4);
	bst.Inorder();
	bst.Remove(2);
	bst.Inorder();
	bst.Remove(3);
	bst.Inorder();
	bst.Remove(8);
	bst.Inorder();
	bst.Remove(6);
	bst.Inorder();
	std::cout << bst.Height(bst.root) << std::endl;
	return 0;
}