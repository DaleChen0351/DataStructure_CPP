#pragma once
#include <iostream>
//头文件中不要写using namespace std;
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
    void display(int i);// 显示自己节点的数据，并且左子树和右子树所有的


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
    //递归查找
    BstNode<Type>* Search(const Element<Type>& data);
    BstNode<Type>* SearchHelper(BstNode<Type>* node, const Element<Type>& data);
     
    //迭代查找
    BstNode<Type>* IterSearcher();
    //提供中序遍历
    //提供delete操作
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


