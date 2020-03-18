#pragma once
#include <iostream>
template <class Comparable>
class RedBlackTree;

template<class Comparable>
class RedBlackNode;



template<class Comparable>
class RedBlackNode
{
    Comparable element;
    RedBlackNode* lchild;
    RedBlackNode* rchild;
    int color;
    RedBlackNode(const Comparable & theElement = Comparable(), // ���캯��Ҳ��˽�е�
        RedBlackNode* left = NULL,
        RedBlackNode* right = NULL,
        int c = RedBlackTree<Comparable>::BLACK)
        : element(theElement), lchild(left), rchild(right),color(c){}

    friend class RedBlackTree<Comparable>;
};

template<class Comparable>
class RedBlackTree
{
public:
    RedBlackTree(const Comparable& negInf);// ���븺�����Ϊα����ֵ
    ~RedBlackTree();
    typedef RedBlackNode<Comparable> Node;
    enum { RED, BLACK};

private:
    Node* nullNode;
    Node* header;
};

template<class Comparable>
inline RedBlackTree<Comparable>::RedBlackTree(const Comparable & negInf)
{
    nullNode = new Node();//
    nullNode->lchild = nullNode->rchild = nullNode;//why?
    header = new Node(negInf);
    header->lchild = header->rchild = nullNode;
}

template<class Comparable>
inline RedBlackTree<Comparable>::~RedBlackTree()
{
    delete nullNode;
    delete header;
}
