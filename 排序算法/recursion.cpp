#include <iostream>
#include "header.h"


void swap(char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

void Permutation(char* p, const int first, const int end)
{
    if (first == end)
    {
        for (int i = 0; i <=end; i++)
        {
            std::cout << p[i];
        }
        std::cout << std::endl;
        return;
    }
    for (int i = first; i <= end; i++)
    {
        swap(p[first], p[i]);
        Permutation(p, first + 1, end);
        swap(p[first], p[i]);
    }

}


