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
    //�������
    void InOrder();
    void InOrderHelper(TreeNode<T>* curNode);
    //ǰ�����
    void preOrder();
    void preOrderHelper();
    //��������

    //�������
    void levelOrder(); //��Ҫʹ�ö���
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

// ǰ�����ȡ���ŵ������� ��Ϊ�Ƚ��ȳ������Կ��԰������������ά�������һά���Ե���ʽ
 template<class T>
 inline void BinaryTree<T>::levelOrderAnother()
 {
     std::queue<TreeNode<T>*>q;//��Ҫʹ��STL�Ķ��� 
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

