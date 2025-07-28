/**
 * @file   HeapSort.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  堆排序 模板函数实现
 * @version 0.1
 * @date 2025-07-22
 *
 * @copyr Copyr (c) 2025
 *
 */

#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

#include <vector>
#include <utility>

template <typename T>
void Heap(std::vector<T>& arr, int n, int i) {
    int x = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[x])
    {
        x = l;
    }
    if (r < n && arr[r] > arr[x])
    {
        x = r;
    }
    if (x != i) 
    {
        std::swap(arr[i], arr[x]);
        Heap(arr, n, x);
    }
}
template <typename T>
void HeapSort(std::vector<T>& arr) 
{
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i --) 
    {
        Heap(arr, n, i);
    }
    for (int i = n - 1; i > 0; i --) 
    {
        std::swap(arr[0], arr[i]);
        Heap(arr, i, 0);
    }
}

#endif // HEAP_SORT_HPP
