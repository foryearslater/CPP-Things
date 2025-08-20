#include "QuickSort.hpp"
#include <iostream>

void QuickSortTest()
{
    std::vector<int>arr = { 6, 4, 1, 3, 5, 2 };
    QuickSort(arr,0,arr.size()-1);
    for (const int& val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
