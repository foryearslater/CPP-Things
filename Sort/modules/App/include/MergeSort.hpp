/**
 * @file   MergeSort.hpp
 * @author nichenglong (2645931757@qq.com)
 * @brief  归并排序 模板类实现
 * @version 0.1
 * @date 2025-07-22
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include <utility>

 //递归
template <typename T>
void MergeSort(std::vector<T>& arr, int l, int r)
{
    std::vector<T> temp(r - l + 1);
    if (l >= r)
    {
        return ;
    }
    int mid = l + r >> 1;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid + 1, r);
   
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)       
    {
        if (arr[i] <= arr[j])
        {
            temp[k ++ ] = std::move(arr[i ++ ]);      
        }       
        else    
        {
            temp[k ++ ] = std::move(arr[j ++ ]);
        }
    }
    while (i <= mid)   
    {
        temp[k ++ ] = std::move(arr[i ++ ]);
    }
    while (j <= r)      
    {
        temp[k ++ ] = std::move(arr[j ++ ]);
    }
 
    for (int i = 0; i <= k; i ++ )  
    {
        arr[i + l] = std::move(tmp[i]);     
    }
}

 //非递归
template <typename T>
void MergeSort_R(std::vector<T>& arr) {
    int n = arr.size();
    std::vector<T> temp(n);

    for (int width = 1; width < n; width *= 2) 
    {
        for (int left = 0; left < n; left += 2 * width) 
        {
            int mid = std::min(left + width, n);     
            int right = std::min(left + 2 * width, n); 
            
            int i = left;    
            int j = mid;  
            int k = left;   
            
            while (i < mid && j < right) 
            {
                if (arr[i] <= arr[j]) 
                {
                    temp[k++] = std::move(arr[i++]);
                } else 
                {
                    temp[k++] = std::move(arr[j++]);
                }
            }
            
            while (i < mid) 
            {
                temp[k++] = std::move(arr[i++]);
            }
    
            while (j < right) 
            {
                temp[k++] = std::move(arr[j++]);
            }
            
            for (int i = 0; i <= k; i ++ )  
            {
                arr[i + l] = std::move(tmp[i]);     
            }
        }
    }
}

#endif // MERGE_SORT_HPP