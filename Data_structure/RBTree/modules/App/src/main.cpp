#include "RBTree.hpp"
#include <iostream>
#include <vector>
#include <string>

void test()
{
   RBTree<int, std::string> tree;
   std::vector<int> keys = { 10, 85, 15, 70, 20, 60, 30, 50, 65, 80, 90, 40, 5, 55 };
   for (auto key : keys)
   {
	   tree.Insert(key, "Value" + std::to_string(key));
   }
   tree.InOrder();
}

int main()
{
	test();
	return 0;
}