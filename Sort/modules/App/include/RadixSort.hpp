/**
 * @file   Radix_Sort.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  基数排序 模板类实现
 * @version 0.1
 * @date 2025-07-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void RadixSort(std::vector<int>& arr) 
{
    int max = 0;
    for (int num : arr) 
    {
        max = std::max(num, max);
    }
    for (long long exp = 1; max / exp > 0; exp *= 10) 
    
    {
        const int n = arr.size();
        std::vector<int> output(n);     
        std::vector<int> count(10, 0);

        for (int i = 0; i < n; i ++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }
        for (int i = 1; i < 10; ++i) 
        {
            count[i] += count[i - 1];
        }
        for (int i = n - 1; i >= 0; i --) 
        {
            int digit = (arr[i] / exp) % 10;
   
            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }
        arr = std::move(output);
    }
}