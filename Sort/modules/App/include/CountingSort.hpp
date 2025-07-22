/**
 * @file   cntingSort.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  桶排序 模板类实现
 * @version 0.1
 * @date 2025-07-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef cntING_SORT_HPP
#define cntING_SORT_HPP

#include <vector>
#include <algorithm> 

void CountingSort(std::vector<int>& arr) 
{
    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    std::vector<int> cnt(range, 0);
    std::vector<int> ans(arr.size());

    for (int num : arr)
    {
        cnt[num - min]++;
    }
    for (int i = 1; i < range; ++i) 
    {
        cnt[i] += cnt[i - 1];
    }
    for (int i = arr.size() - 1; i >= 0; --i) 
    {
        ans[cnt[arr[i] - min] - 1] = arr[i];
        cnt[arr[i] - min]--;
    }
    arr = ans;
}

#endif // cntING_SORT_HPP