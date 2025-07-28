/**
 * @file   BucketSort.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  桶排序 模板函数实现
 * @version 0.1
 * @date 2025-07-22
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef BUCKET_SORT_HPP
#define BUCKET_SORT_HPP

#include <vector>
#include <algorithm> 
#include <iostream>
#include <cmath>

void BucketSort(std::vector<int>& arr, int num_buckets = 0) 
{
    if (num_buckets <= 0) 
    {
        num_buckets = std::max(static_cast<int>(sqrt(arr.size())),  static_cast<int>(arr.size() / 10));
        num_buckets = std::max(num_buckets, 1);
    }
    auto min_max = std::minmax_element(arr.begin(), arr.end());
    int min = *min_max.first;
    int max = *min_max.second;
    
    if (min == max) return;
    
    std::vector<std::vector<int>> buckets(num_buckets);
    
    double range = (max - min + 1.0) / num_buckets;
    
    for (int num : arr) 
    {
        int bucket_idx = static_cast<int>((num - min) / range);
        if (bucket_idx >= num_buckets) 
        {
            bucket_idx = num_buckets - 1;
        }
        buckets[bucket_idx].push_back(num);
    }
    
    for (auto& bucket : buckets) 
    {
        if (bucket.size() <= 32) 
        {
            for (int i = 1; i < bucket.size(); i++) 
            {
                int key = bucket[i];
                int j;
                for (j = i - 1; j >= 0 && bucket[j] > key; j--)
                {
                    bucket[j + 1] = bucket[j];
                }
                bucket[j + 1] = key;
            }
        } 
        else 
        {
            std::sort(bucket.begin(), bucket.end());
        }
    }
    
    int idx = 0;
    for (const auto& bucket : buckets) 
    {
        for (int num : bucket) 
        {
            arr[idx++] = num;
        }
    }
}

#endif // BUCKET_SORT_HPP