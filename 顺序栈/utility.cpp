#include "utility.h"
#include <iostream>


template<class T>
void ChangeSeqStackCapacity(T* & arr, const int oldSize, const int newSize)
{
    if (arr == NULL)
    {
        return;
    }
    if (oldSize < 1 || newSize < 1)
    {
        throw "stack capacity must be > 0";
    }

    T* tempArr = new T[newSize];
    std::copy(arr, arr + oldSize, newSize);
    delete[] arr;
    arr = tempArr;
}