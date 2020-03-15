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


//����������Ĳ������
template<class Type>
Boolean BinarySearchTree<Type>::Insert(const Element<Type>& data)
{
    BstNode<Type>* curNode = root;
    BstNode<Type>* fatherNode = NULL;
    // �Ȳ���λ��
    while (curNode != NULL)
    {
        //��¼��ǰ�ڵ�Ϊ�¸�ѭ���ĸ��ڵ�
        fatherNode = curNode;
        // ѭ���з��ֽڵ��Ѿ������ˣ���ֱ�ӷ���
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
    //�½��ڵ�
    curNode = new BstNode<Type>;
    curNode->data = data;
    curNode->lchild = curNode->rchild = NULL;

    //������ϵ
        //����ǿ���
    if (root == NULL)
    {
        root = curNode;
    }
   
        //�����������
    else if (fatherNode->data.key > curNode->data.key)
    {
        fatherNode->lchild = curNode;
    }
        //�����������
    else
    {
        fatherNode->rchild = curNode;
    }
    return TRUE;
}

//����������Ĳ�ѯ����
//�ݹ鷽ʽ
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