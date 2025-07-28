/**
 * @file ShellSort.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  希尔排序 模板函数实现
 * @version 0.1
 * @date 2025-07-22
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <vector>
#include <utility>

template <typename T>
void ShellSort(std::vector<T>& arr) 
{
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) 
    {
        for (int i = gap; i < n; ++i) 
        {
            T temp = std::move(arr[i]);
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = std::move(arr[j - gap]);
            }
            arr[j] = std::move(temp);
        }
    }
}

#endif // SHELL_SORT_HPP