#include "seqstack.h"



template<class T>
SeqStack<T>::SeqStack(int stackcapacity):capacity(stackcapacity)
{
    if (stackcapacity < 1)
    {
        throw "stack capacity must be > 0";
    }
 
    stack = new T[capacity];
    top = -1;
}

template<class T>
void SeqStack<T>::Push(const T& item)
{
    if ((top+1) == capacity)
    {
        ChangeSeqStackCapacity(stack, capacity, capacity * 2);
        capacity *= 2;
    }
    
    stack[++top] = item;
}
template<class T>
inline void SeqStack<T>::Pop()
{
    if (Is_Empty())
    {
        throw "the stack is empty, can not pop item out";
    }
    stack[top].~T();// ? µ÷ÓÃÎö¹¹
    top--;
}

template <class T>
SeqStack<T>::~SeqStack()
{
   
    
        delete[]stack;
    
}
