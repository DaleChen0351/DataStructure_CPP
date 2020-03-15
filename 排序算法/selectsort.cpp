#include <iostream>
#include "header.h"

int  SelectSort(int *a, const int len)
{
    int retNum = 0;
    // 每次扫描都找出一个最小值，并交换放到最左边
    for (int i = 0; i < len - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            retNum++;
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    return retNum;
}