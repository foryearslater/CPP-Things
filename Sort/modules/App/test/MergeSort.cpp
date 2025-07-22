#include "MergeSort.hpp"
#include <iostream>
#include <vector>

void MergeSortTest()
{
    std::vector<int>arr = { 6, 4, 1, 3, 5, 2 };

    auto temp = arr;
    MergeSort_R(arr);
    for (const int& val : arr)
    {
        std::cout << val << " ";
    }


    int n = arr.size();
    MergeSort(temp, 0, n - 1);
    std::cout << std::endl;
    for (const int& val : temp)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}