/**
 * @file   BubbleSort.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  冒泡排序 模板函数实现
 * @version 0.1
 * @date 2025-07-22
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP
#include <vector>
#include <utility> 

template <typename T>
void BubbleSort(std::vector<T>& arr) 
{
    int n = arr.size();
    bool flag ;
    for (int i = 0; i < n - 1; i ++) 
    {
        flag = false;
        for (int j = 0; j < n - 1 - i; j ++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                std::swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (false == flag) 
        {
            break;
        }
    }
}

#endif // BUBBLE_SORT_HPP