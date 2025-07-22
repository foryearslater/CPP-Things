#include "SelectionSort.hpp"
#include <iostream>
#include <vector>

void SelectionSortTest()
{
    std::vector<int>arr = { 6, 4, 1, 3, 5, 2 };
    SelectionSort(arr);
    for (const int& val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}