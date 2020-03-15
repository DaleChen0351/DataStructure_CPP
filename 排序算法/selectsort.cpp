#include <iostream>
#include "header.h"

int  SelectSort(int *a, const int len)
{
    int retNum = 0;
    // ÿ��ɨ�趼�ҳ�һ����Сֵ���������ŵ������
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