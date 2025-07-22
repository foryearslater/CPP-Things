/**
 * @file   InsertionSort.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  插入排序 模板类实现
 * @version 0.1
 * @date 2025-07-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>
#include <utility>

template <typename T>
void InsertionSort(std::vector<T>& arr) 
{
    int n = arr.size();
    for (int i = 1; i < n; i ++) 
    {
        T key = std::move(arr[i]);
        int j ;
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = std::move(arr[j]);
            j--;
        }
        arr[j + 1] = std::move(key);
    }
}

#endif // INSERTION_SORT_HPP