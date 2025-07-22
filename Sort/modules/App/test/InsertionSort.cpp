#include "InsertionSort.hpp"
#include <iostream>
#include <vector>

void InsertionSortTest()
{
    std::vector<int>arr = { 6, 4, 1, 3, 5, 2 };
    InsertionSort(arr);
    for (const int& val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}