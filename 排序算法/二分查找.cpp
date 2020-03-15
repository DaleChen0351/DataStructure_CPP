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
//���õݹ���㷨�����۰����
int recursion_binarySearch(int* arr, int low, int high, const int& target)
{
    int mid = (low + high) / 2;
    //��������1 û�ҵ�Ŀ��
    if (low > high)
    {
        return -1;
    }
    //��������2 �ҵ���Ŀ��
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