#include <iostream>

using namespace std;



void InsertionSort(int len, int* arr)
{
    int in, out;
    for (int i = 1; i < len; i++)
    {
        int temp = arr[i];
        int in = i;
        while (temp < arr[in - 1] && )
        {
            arr[in] = arr[in - 1];
            in--;

        }
        arr[in] = temp;
    }

}