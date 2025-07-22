#include "BubbleSort.hpp"
#include <iostream>
#include <vector>

void BubbleSortTest()
{
    std::vector<int>arr = { 6, 4, 1, 3, 5, 2 };
    BubbleSort(arr);
    for (const int& val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}