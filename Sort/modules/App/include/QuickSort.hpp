/**
 * @file   QuickSort.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  快速排序 模板函数实现
 * @version 0.1
 * @date 2025-07-22
 *
 * @copyr Copyr (c) 2025
 *
 */

#ifndef QUICK_SORT_R_HPP
#define QUICK_SORT_R_HPP

#include <vector>
#include <utility>
#include <stack>

//递归
template <typename T>
void QuickSort(vector<T>& arr, int l, int r)
{
    if (l == r)
    {
        return ;
    }
    int i = l - 1, j = r + 1;
    T x = arr[(l + r) / 2];
    while (i < j)
    {
        do i++; while (arr[i] < x);
        do j--; while (arr[j] > x);
        if (i < j) 
        {
            std::swap(arr[i], arr[j]);
        }
    }
    QuickSort(arr, l , j);
    QuickSort(arr, j + 1 , r);
}

//非递归  用栈
template <typename T>
void QuickSort_R(std::vector<T>& arr, int l, int r) 
{
    std::stack<std::pair<int, int>> stk;
    stk.push({l, r});  

    while (!stk.empty()) 
    {
        auto [l, r] = stk.top();
        stk.pop();
        int i = l - 1, j = r + 1;
        T x = arr[(l + r) / 2];  

        while (i < j) 
        {
            do i++; while (arr[i] < x);
            do j--; while (arr[j] > x);
            if (i < j) 
            {
                std::swap(arr[i], arr[j]);
            }
        }
      
        if (j + 1 < r) stk.push({j + 1, r}); 
        if (l < j) stk.push({l, j});            
    }
}
#endif // QUICK_SORT_R_HPP