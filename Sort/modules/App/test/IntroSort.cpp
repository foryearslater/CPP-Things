#include "IntroSort.hpp"
#include <iostream>
#include <vector>

void IntroSortTest()
{
    std::vector<int>arr = { 6, 4, 1, 3, 5, 2 };
    IntroSort(arr);
    for (const int& val : arr)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

