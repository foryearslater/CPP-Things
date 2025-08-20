/**
 * @file SelectionSort.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  选择排序 模板函数实现
 * @version 0.1
 * @date 2025-07-22
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once
#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <vector>
#include <utility>

template <typename T>
void SelectionSort(std::vector<T> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if (min_idx != i)
        {
            std::swap(arr[i], arr[min_idx]);
        }
    }
}

#endif // SELECTION_SORT_HPP