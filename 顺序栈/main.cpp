#include <iostream>
#include "seqstack.h"
#include "seqstack.cpp"
#include "utility.h"
#include "utility.cpp"

using namespace std;



int main()
{
    SeqStack<double> mystack(5);
    // cout <<"top item = "<< mystack.Top() << endl;  throw²âÊÔ
    mystack.Push(1.11);
    cout << "capacity = " << mystack.Capacity() << endl;
    mystack.Push(2.22);
    mystack.Push(3.11);
    mystack.Push(4.22);
    mystack.Push(5.11);
    cout << "capacity = " << mystack.Capacity() << endl;
    mystack.Push(6.22);
    cout << "capacity = " << mystack.Capacity() << endl;
}