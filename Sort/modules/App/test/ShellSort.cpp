#include "ShellSort.hpp"
#include <iostream>
#include <vector>

void ShellSortTest()
{
    std::vector<int>arr = { 6, 4, 1, 3, 5, 2 };
    ShellSort(arr);
    for (const int& val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}