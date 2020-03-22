#include "avl.h"
using namespace std;
int height(Node * n)
{
    if (n == NULL)
        return 0;

    return n->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

Node * newNode(int key)
{
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

Node * rightRotate(Node * y)
{
    Node* x = y->left;
    Node* t2 = x->right;

    y->left = t2;
    x->right = y;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
   
}

Node * leftRotate(Node * x)
{
    Node* y = x->right;
    Node* t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return y;
}

int getBalanceFactor(Node * n)
{
    if (n == NULL)
    {
        return 0;
    }
    return height(n->left) - height(n->right);
}

Node* insert(Node* node, int key)
{
// BST�ı�׼�������
   //��һ���ڵ�
    if (node == NULL)
        return (newNode(key));
    // �ȴ���������ұߵ��ӽڵ㣬�ٿ��Ǳ��ڵ��(���µ��ϱ�������Ƿ���ƽ���
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if(key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else// BST���в�������ͬ�ļ�ֵ
    {
        return node;
    }
// ���±��ڵ�ĸ߶�
    node->height = 1 + max(height(node->left), height(node->right));
// ����balance factor ����ȥ�������ڵ��Ƿ���ƽ���
    int balancefactor = getBalanceFactor(node);

// ��������ֱ�����
    //LL
    if (balancefactor > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }
    //RR
    if (balancefactor < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }
    // LR
    if (balancefactor > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // RL
    if (balancefactor < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node * root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root->key << " ";
    inOrder(root->right);
}
