#include "CountingSort.hpp"
#include <iostream>
#include <vector>

void CountingSortTest()
{
    std::vector<int>arr = { 6, 4, 1, 3, 5, 2 };
    CountingSort(arr);
    for (const int& val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}