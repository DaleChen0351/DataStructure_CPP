#pragma once
#include <iostream>
template <class Comparable>
class RedBlackTree;

template<class Comparable>
class RedBlackNode;



template<class Comparable>
class RedBlackNode
{
public:// temp
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
    void insert(const Comparable& x);

//private:
public://temp
    Node* nullNode;
    Node* header;
    // for insert function
    Node* current;
    Node* parent;
    Node* grand;//�游
    Node* great;//����

    void rotateWithLeftChild(Node* & k2)const;// ����ת ����Ĳ��������ϵ�
    void rotateWithRightChild(Node*& k1)const;// ����ת
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

template < class Comparable>
void RedBlackTree<Comparable>::insert(const Comparable& x)
{
    //init
    current = parent = grand = header;
    nullNode->element = x; // why?

    //postion
    while (current->element != x)
    {
        great = grand;
        grand = parent;
        parent = current;
       
        current = x < current->element ? current->lchild : current->rchild;
    }
    //find the same element
    if (current != nullNode)
    {
        std::cout << "find the same id" << std::endl;
        return;
    }
    
    current = new Node(x, nullNode, nullNode); 
    if (x < parent->element)
    {
        parent->lchild = current;
    }
    else if(x>parent->element)
    {
        parent->rchild = current;
    }
    //���������� + �Զ�ƽ�� -> �����
    
}  
// ��ת
template<class Comparable>
void RedBlackTree<Comparable>::rotateWithLeftChild(Node* & k2)const
{
    Node* k1 = k2->lchild;
    k2->lchild = k1->rchild;
    k1->rchild = k2;
    k2 = k1;
}
//��ת
template<class Comparable>
void RedBlackTree<Comparable>::rotateWithRightChild(Node* & k1)const
{
    Node* k2 = k1->rchild;
    k1->rchild = k2->lchild;
    k2->lchild = k1;
    k1 = k2;
}
