#include <iostream>
#include "header.h"



int  binarySearch(int *arr, const int len, const int num)
{
    int low = 0;
    int high = len - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        std::cout << "arr[mid] = " <<arr[mid] << std::endl;
        if (num == arr[mid])
        {
            return mid;
        }
        else if(num > arr[mid])
        {
            low = mid + 1;
        }
        else if (num < arr[mid])
        {
            high = mid - 1;
        }
    }

    return -1;
   
}
//利用递归的算法进行折半查找
int recursion_binarySearch(int* arr, int low, int high, const int& target)
{
    int mid = (low + high) / 2;
    //结束条件1 没找到目标
    if (low > high)
    {
        return -1;
    }
    //结束条件2 找到了目标
    if (arr[mid] == target)
    {
        return mid;
    }

    if (target > arr[mid])
    {
        low = mid + 1;
    }
    else if (target < arr[mid])
    {
        high = mid - 1;
    }
    return recursion_binarySearch(arr, low, high, target);
}