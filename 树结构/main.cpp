
#include <iostream>
#include "binarytree.h"
#include "binarySearchTree.h"
#include "binarySearchTree.cpp"
using namespace std;

void test_01()
{
    
    //�����ڵ�
    TreeNode<char>nodeAdd('+');
    TreeNode<char>nodeSub('-');
    TreeNode<char>nodeE('E');
    TreeNode<char>nodeMul('*');
    TreeNode<char>nodeD('D');
    TreeNode<char>nodeDiv('/');
    TreeNode<char>nodeC('C');
    TreeNode<char>nodeA('A');
    TreeNode<char>nodeB('B');

    //����������
    BinaryTree<char>tree(&nodeAdd);
    //������ϵ
    nodeAdd.lchild = &nodeSub;
    nodeAdd.rchild = &nodeE;
    nodeSub.lchild = &nodeMul;
    nodeSub.rchild = &nodeD;
    nodeMul.lchild = &nodeDiv;
    nodeMul.rchild = &nodeC;
    nodeDiv.lchild = &nodeA;
    nodeDiv.rchild = &nodeB;

    tree.InOrder();
    cout << "ʹ�ò������" << endl;
    tree.levelOrder();

    
}

void test_binarySearchTree()
{
    BinarySearchTree<int>tree;
    Element<int>a, b, c, d, e, f, g, h, i, j;
    a.key = 5;
    b.key = 3;
    c.key = 11;
    d.key = 3;
    e.key = 15;
    f.key = 2;
    g.key = 8;
    h.key = 22;
    i.key = 20;
    j.key = 9;

    cout << endl;
    cout << tree.Insert(a) << endl;
    cout << tree.Insert(b) << endl;
    cout << tree.Insert(c) << endl;
    cout << tree.Insert(d) << endl;
    cout << tree.Insert(e) << endl;
    cout << tree.Insert(f) << endl;
    cout << tree.Insert(g) << endl;
    cout << tree.Insert(h) << endl;
    /*cout << tree.Insert(i) << endl;
    cout << tree.Insert(j) << endl;
    cout << tree.Insert(a) << endl;*/

    tree.display();
    
    BstNode<int>* p =    tree.Search(f);
    cout << "���õݹ�ķ�ʽ�ҵ���������" << endl;
    cout << p->data.key << endl;

}
int main()
{
    //test_01();
    test_binarySearchTree();
}