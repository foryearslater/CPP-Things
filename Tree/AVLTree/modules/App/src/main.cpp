#include "AVLTree.hpp"

int main()
{
	AVLTree<int, int> tree;
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 ,1,5,12,20 };
	for (size_t i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		tree.Insert(a[i], i);
	}

	tree.Inorder();
	std::cout << "height=" << tree.Height() << std::endl;
	bool ret = tree.IsBalanced();
	if (ret == true)
		std::cout << "This AVLTree is in balanced !" << std::endl;
	else
		std::cout << "This AVLTree is in a state of imbalance !" << std::endl;
	return 0;
}