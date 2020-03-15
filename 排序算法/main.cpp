#include <iostream>
#include "header.h"
using namespace std;

bool Mycompare(int a, int b)
{
    if (a > b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printArry(int* arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test_01()
{
    int arr[] = { 1,23,5,7, 19, 2, 4,16, 8,0,11,23,45,37, 119, 22, 114,16, 78,110 };
    int len = sizeof(arr) / sizeof(int);
    int swapNum = bubbleSort(arr, len, Mycompare);
    cout << "swapNum = " << swapNum << endl;
    printArry(arr, len);

    int target = 119;
    cout << " 利用循环方式查找 " << target << endl;
    int ret = binarySearch(arr, len, target);
    cout << "ret == " << ret << endl;
    cout << " 利用递归方式查找 " << target << endl;
    int ret2 = recursion_binarySearch(arr, 0, len - 1, target);
    cout << "ret == " << ret2<< endl;
}
void test_02()
{
    int arr[] = { 1,23,5,7, 19, 2, 4,16, 8,0,11,23,45,37, 119, 22, 114,16, 78,110 };
    int len = sizeof(arr) / sizeof(int);
    int swapNum = SelectSort(arr, len);
    cout << "swapNum = " << swapNum << endl;
    printArry(arr, len);
}

int jiechen(int n)
{
    if (n == 0) //循环结束的条件。所以，递归的核心是确定递归结束的条件。
    {
        return 1;
    }
    return n * jiechen(n - 1);// n! = n* (n-1)!
}


void test_03()
{
    int num = 3;
    int ret = jiechen(num);
    cout << num << "的阶乘是 " << ret << endl;

    cout << "利用迭代的方式计算阶乘" << endl;
    int result = 1;
    for (int i = num; i > 0; i--)
    {
        result *= (i);
    }
    cout << result << endl;

}

void test_04()
{
    char arr[] = "abc";
    int len = sizeof(arr);
    cout << "len = " << len << endl; // len  = 4;
    Permutation(arr, 0, 2);
}
int main()
{
    //test_01();
    //test_03();
    test_04();
}