#include "binarySearchTree.h"
using namespace std;

template<class Type>
void BstNode<Type>::display(int i)
{
    cout << "posistion = " << i << "    key = " << this->data.key << endl;
    if(this->lchild != NULL)
        this->lchild->display(2 * i);
    if(this->rchild != NULL)
        this->rchild->display(2 * i + 1);
}


//二叉查找树的插入操作
template<class Type>
Boolean BinarySearchTree<Type>::Insert(const Element<Type>& data)
{
    BstNode<Type>* curNode = root;
    BstNode<Type>* fatherNode = NULL;
    // 先查找位置
    while (curNode != NULL)
    {
        //记录当前节点为下个循环的父节点
        fatherNode = curNode;
        // 循环中发现节点已经存在了，则直接返回
        if (curNode->data.key == data.key)
        {
            return FALSE;
        }
        else if (curNode->data.key > data.key)
        {
            curNode = curNode->lchild;
        }
        else
        {
            curNode = curNode->rchild;
        }
    }
    //新建节点
    curNode = new BstNode<Type>;
    curNode->data = data;
    curNode->lchild = curNode->rchild = NULL;

    //建立关系
        //如果是空树
    if (root == NULL)
    {
        root = curNode;
    }
   
        //如果是左子树
    else if (fatherNode->data.key > curNode->data.key)
    {
        fatherNode->lchild = curNode;
    }
        //如果是右子树
    else
    {
        fatherNode->rchild = curNode;
    }
    return TRUE;
}

//二叉查找树的查询操作
//递归方式
template<class Type>
BstNode<Type>* BinarySearchTree<Type>::Search(const Element<Type>& xdata)
{
    return SearchHelper(root, xdata);
}

template<class Type>
BstNode<Type>* BinarySearchTree<Type>::SearchHelper(BstNode<Type>* curNode, const Element<Type>& xdata)
{
    if (curNode == NULL)
    {
        return NULL;
    }
    if (curNode->data.key == xdata.key)
    {
        return curNode;
    }
    else if(curNode->data.key > xdata.key)
    {
        return SearchHelper(curNode->lchild, xdata);
    }
    else
    {
        return SearchHelper(curNode->rchild, xdata);
    }
}