#include "RadixSort.hpp"
#include <iostream>
#include <vector>

void RadixSortTest()
{
    std::vector<int>arr = { 6, 4, 1, 3, 5, 2 };
    RadixSort(arr);
    for (const int& val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}