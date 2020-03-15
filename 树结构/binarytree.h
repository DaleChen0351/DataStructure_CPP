#pragma once

#include <iostream>
#include <queue>

template<class T>
class TreeNode
{
public:
    T data;
    TreeNode<T>* lchild;
    TreeNode<T>*rchild;
    TreeNode(T userData):data(userData)
    {
        lchild = NULL;
        rchild = NULL;
    }
};

template<class T>
class BinaryTree
{
public:
    BinaryTree(TreeNode<T>* rootNode) :root(rootNode) {};
    //中序遍历
    void InOrder();
    void InOrderHelper(TreeNode<T>* curNode);
    //前序遍历
    void preOrder();
    void preOrderHelper();
    //后续遍历

    //层序遍历
    void levelOrder(); //需要使用队列
    void levelOrderAnother();
    void visit(TreeNode<T>* curNode);
private:
    TreeNode<T>* root;
};

template<class T>
inline void BinaryTree<T>::visit(TreeNode<T>* curNode)
{
    std::cout << curNode->data << std::endl;
}


template<class T>
 void BinaryTree<T>::InOrder()
{
     InOrderHelper(root);
}

 template<class T>
 void BinaryTree<T>::InOrderHelper(TreeNode<T>* curNode)
 {
     if (curNode == NULL)
     {
         return;
     }
     InOrderHelper(curNode->lchild);
     visit(curNode);
     InOrderHelper(curNode->rchild);
 }

 template<class T>
 void BinaryTree<T>::levelOrder()
 {
     std::queue<TreeNode<T>*>q;
     q.push(root);
     while (!q.empty())
     {
         TreeNode<T>* curNode = q.front();
         q.pop();
         visit(curNode);
         if (curNode->lchild)
         {
             q.push(curNode->lchild);
         }
         if (curNode->rchild)
         {
             q.push(curNode->rchild);
         }
        

     }
 }

// 前序遍历取数放到队列中 因为先进先出，所以可以按层遍历，将二维遍历变成一维线性的形式
 template<class T>
 inline void BinaryTree<T>::levelOrderAnother()
 {
     std::queue<TreeNode<T>*>q;//需要使用STL的队列 
     TreeNode<T>* curNode = root;
     while (curNode)
     {
         visit(curNode);
         if (curNode->lchild)
         {
             q.push(curNode->lchild);
         }
         if (curNode->rchild)
         {
             q.push(curNode->rchild);
         }
         if (q.empty())
         {
             return;
         }
         curNode = q.front();
         q.pop();
     }
 }

