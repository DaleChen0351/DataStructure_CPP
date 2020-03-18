#include <iostream>
#include "RedBlackTree.h"
using namespace std;

int main()
{
    const int NEG_INF = -99999;
    RedBlackTree<int>tree(NEG_INF);

    tree.insert(30);
    tree.insert(15);
    tree.insert(70);
    tree.insert(20);

    RedBlackTree<int>::Node * root;
    root = tree.header->rchild;
    cout <<root->element << endl;
    cout << root->lchild->element << endl;
    cout << root->rchild->element << endl;
    cout << root->lchild->rchild->element << endl;

    //右旋
    cout << "向右转" << endl;
    tree.rotateWithLeftChild(root);
    cout << root->element << endl;
    cout << root->rchild->element << endl;
    cout << root->rchild->lchild->element << endl;
    cout << root->rchild->rchild->element << endl;

    cout << "向左转" << endl;
    tree.rotateWithRightChild(root);
    cout << root->element << endl;
    cout << root->lchild->element << endl;
    cout << root->rchild->element << endl;
    cout << root->lchild->rchild->element << endl;
    cout << "ok" << endl;
    system("pause");
   
}