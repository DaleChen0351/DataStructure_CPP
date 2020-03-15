#pragma once

#include "utility.h"

template<class T>
class SeqStack
{
public:
    SeqStack(int stackcapacity = 10);
    ~SeqStack();
    void Push(const T& item);
    void Pop();
    T& Top()const;
    bool Is_Empty()const;
    int Capacity()const { return capacity; }
private:
    int capacity;
    int top;
    T* stack;
};

template<class T>
inline bool SeqStack<T>::Is_Empty()const
{
    return top == -1;
}

template<class T>
inline T& SeqStack<T>::Top()const
{
    if (Is_Empty())
    {
        throw "stack is empty";
    }
    return stack[top];
}


