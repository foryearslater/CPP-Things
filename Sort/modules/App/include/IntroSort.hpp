/**
 * @file   IntroSort.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  内省排序 模板函数实现
 * @version 0.1
 * @date 2025-07-28
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef INTRO_SORT_HPP
#define INTRO_SORT_HPP

#include <iostream>
#include <vector>
#include <algorithm> 
#include <cmath>     
#include <functional>

//最小阙值
const int SMALL_SORT_THRESHOLD = 16; 

/**
* @brief 插入排序的辅助实现.用于处理内省排序中的小规模子数组.
* @tparam T 迭代器类型，应为 RandomAccessIterator.
* @tparam Cmp 比较器类型.
* @param begin 指向待排序范围的起始迭代器.
* @param end 指向待排序范围的结束迭代器（不包含此元素）.
* @param Cmp 比较函数对象.
*/
template <typename T, typename Cmp>
void Insertion_Sort(T begin, T end, Cmp cmp) 
{
    if (begin == end) return;
    for (T i = begin + 1; i != end; i ++) 
    {
        typename std::iterator_traits<T>::value_type key = std::move(*i); 
        T j = i;
        while (j != begin && cmp(key, *(j - 1))) 
        {
            *j = std::move(*(j - 1));
            --j;
        }
        *j = std::move(key);
    }
}
/**
* @brief 堆化操作的辅助实现. 用于维护最大堆的性质，是堆排序的核心.
* @tparam T 迭代器类型，应为 RandomAccessIterator.
* @tparam Cmp 比较器类型.
* @param begin 堆的起始迭代器（通常是整个数组的起始）.
* @param end 堆的结束迭代器（表示当前堆的有效范围）.
* @param root 当前需要进行堆化操作的根节点迭代器.
* @param Cmp 比较函数对象.
*/

template <typename T, typename Cmp>
void Heap(T begin, T end, T root, Cmp cmp) 
{
    auto heap_size = std::distance(begin, end); 
    auto root_idx = std::distance(begin, root);

    auto max = root_idx;
    auto left = 2 * root_idx + 1;
    auto right = 2 * root_idx + 2;

    if (left < heap_size && cmp(*(begin + max), *(begin + left))) 
    {
        max = left;
    }
    if (right < heap_size && cmp(*(begin + max), *(begin + right))) 
    {
        max = right;
    }

    if (max != root_idx)
    {
        std::swap(*(begin + root_idx), *(begin + max));
        Heap(begin, end, begin + max, cmp);
    }
}
/**
 * @brief 堆排序的辅助实现.作为快速排序在最坏情况下的备用算法，确保 O(N log N) 的时间复杂度.
 * @tparam T 迭代器类型，应为 RandomAccessIterator.
 * @tparam Cmp 比较器类型.
 * @param begin 指向待排序范围的起始迭代器.
 * @param end 指向待排序范围的结束迭代器（不包含此元素）.
 * @param Cmp 比较函数对象.
 */
template <typename T, typename Cmp>
void Heap_sort(T begin, T end, Cmp cmp) 
{
    auto n = std::distance(begin, end);

    for (long i = n / 2 - 1; i >= 0; --i) 
    {
        Heap(begin, end, begin + i, cmp);
    }

    for (long i = n - 1; i > 0; --i) 
    {
        std::swap(*begin, *(begin + i));
        Heap(begin, begin + i, begin, cmp);
    }
}    

/**
 * @brief 快速排序的分区操作的辅助实现.选择一个基准元素，并将数组分成两部分：小于基准的和大于基准的.
 * @tparam T 迭代器类型，应为 RandomAccessIterator.
 * @tparam Cmp 比较器类型.
 * @param begin 指向待分区范围的起始迭代器.
 * @param end 指向待分区范围的结束迭代器（不包含此元素）.
 * @param Cmp 比较函数对象.
 * @return T 返回基准元素最终所在的位置迭代器.
 */
template <typename T, typename Cmp>
T Quick_Sort(T begin, T end, Cmp cmp) 
{
    T mid = begin + std::distance(begin, end) / 2;
    T last = end - 1; 

    if (cmp(*mid, *begin)) 
    {
        std::swap(*begin, *mid);
    }
    if (cmp(*last, *begin)) 
    {
        std::swap(*begin, *last);
    }
    if (cmp(*last, *mid)) 
    {
        std::swap(*mid, *last);
    }
    typename std::iterator_traits<T>::value_type pivot_val = std::move(*mid);
    std::swap(*mid, *last); 

    T i = begin; 
    for (T j = begin; j != last; ++j) 
    {
        if (cmp(*j, pivot_val)) 
        {
            std::swap(*i, *j);
            ++i;
        }
    }
    std::swap(*i, *last);
    return i; 
}
/**
 * @brief 内省排序的递归主循环实现.结合了快速排序、堆排序和插入排序.
 * @tparam T 迭代器类型，应为 RandomAccessIterator.
 * @tparam Cmp 比较器类型.
 * @param begin 指向待排序范围的起始迭代器.
 * @param end 指向待排序范围的结束迭代器（不包含此元素）.
 * @param Cmp 比较函数对象.
 * @param dep 递归深度限制.当达到此限制时，切换到堆排序.
 */
template <typename T, typename Cmp>
void IntroSort_Loop(T begin, T end, Cmp cmp, int dep) 
{
    long n = std::distance(begin, end);
    if (n <= 1) 
    {
        return;
    }

    if (n < SMALL_SORT_THRESHOLD) 
    {
        Insertion_Sort(begin, end, cmp);
        return;
    }

    if (dep == 0) 
    {
        Heap_sort(begin, end, cmp);
        return;
    }

    T pivot_pos = Quick_Sort(begin, end, cmp);

    IntroSort_Loop(begin, pivot_pos, cmp, dep - 1);      
    IntroSort_Loop(pivot_pos + 1, end, cmp, dep - 1); 
}

/**
 * @brief 内省排序算法的公共接口.
 *        内省排序是一种混合排序算法，结合了快速排序、堆排序和插入排序的优点.
 *        它在平均情况下使用快速排序，在最坏情况下（递归深度过深）退化为堆排序，
 *        在小规模子数组上则切换到插入排序.
 *
 * @tparam T 迭代器类型，应为 RandomAccessIterator.
 * @tparam Cmp 比较器类型，一个可调用对象，默认为 std::less.
 * @param begin 指向待排序范围的起始迭代器.
 * @param end 指向待排序范围的结束迭代器（不包含此元素）.
 * @param Cmp 比较函数对象，用于定义元素的排序顺序.
 */
template <typename T, typename Cmp = std::less<T>>
void IntroSort(std::vector<T>& arr, Cmp cmp = Cmp())
{
    long n = arr.size();
    int dep = 0;
    if (n) 
    {
        dep = 2 * static_cast<int>(std::log2(n));
    }
    IntroSort_Loop(arr.begin(), arr.end(), cmp, dep);
}
#endif // INTRO_SORT_HPP


