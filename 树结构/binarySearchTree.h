#pragma once
#include <iostream>
//ͷ�ļ��в�Ҫдusing namespace std;
enum Boolean
{
    FALSE,
    TRUE
};
template<class Type>
class Element
{
public:
    Type key;
    //other data
};
template<class Type> class BinarySearchTree;
template<class Type>
class BstNode
{
    friend class BinarySearchTree<Type>;
public:
    void display(int i);// ��ʾ�Լ��ڵ�����ݣ����������������������е�


    Element<Type> data;
    BstNode*lchild;
    BstNode*rchild;
    
};

template<class Type>
class BinarySearchTree
{
public:
    BinarySearchTree(BstNode<Type>* init = NULL): root(init){}
    Boolean Insert(const Element<Type>& data);
    //�ݹ����
    BstNode<Type>* Search(const Element<Type>& data);
    BstNode<Type>* SearchHelper(BstNode<Type>* node, const Element<Type>& data);
     
    //��������
    BstNode<Type>* IterSearcher();
    //�ṩ�������
    //�ṩdelete����
    void display()
    {
        if(root != NULL)
            root->display(1);
    }

private:
    BstNode<Type>* root; 
};




//class Singleton
//{
//   static Singleton& GetInstance();
//    
//private:
//    Singleton(int number):num(number){}
//    int num;
//
//};
//
//Singleton& Singleton::GetInstance()
//{
//
//    
//}


