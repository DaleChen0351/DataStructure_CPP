#include <iostream>
#include"header.h"


int  bubbleSort(int* arr, int len, bool(*mycompare)(int ,int ))
{
    int retNum = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
           
            if (mycompare(arr[j], arr[j + 1]))
            {
                retNum++;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return retNum;
}