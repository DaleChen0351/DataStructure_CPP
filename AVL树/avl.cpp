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

Node * minValueNode(Node * node)
{
    Node* curNode = node;
    // loop down to find the leftmost leaf.
    while (curNode->left!=NULL)
    {
        curNode = curNode->left;
    }
    return curNode;//�ҵ���  in order successor
}

Node* deleteNode(Node* root, int key)
{
    //���ĸ�Ϊ�սڵ�
    if (root == NULL)
    {
        return root;
    }
    // find the postion of deleted node
    if (key < root->key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = deleteNode(root->right, key);
    }
    // find it ,delete it 
    else
    {
        // ��ɾ���Ľڵ�������һ���ӽڵ�
        if (root->left == NULL || root->right == NULL)
        {
            Node* temp = root->left ? root->left : root->right;
            // No child;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
            }
            free(temp);

        }
        // ��ɾ���Ľڵ��������ӽڵ�
        else
        {
            // node with two children : Get the inorder
                // successor (smallest in the right subtree)  
            Node* temp = minValueNode(root->right);

            // Copy the inorder successor's  
            // data to this node  
            root->key = temp->key;

            // Delete the inorder successor  
            root->right = deleteNode(root->right,
                temp->key);
        }



    }

    // If the tree had only one node 
        // then return  
    if (root == NULL)
        return root;

    // Update ��ǰ�ڵ�ĸ߶�
    root->height = max(height(root->left), height(root->right)) + 1;

    // ����balance factor
    int balance = getBalanceFactor(root);

    // ���ݼ�������תƽ��
        //left left
    if (balance > 1 && getBalanceFactor(root->left) >= 0)// ע������ĵ��ںţ����ж���·��������ʵ��balance > 1ʱ�����ȿ���left left����Ϊ����Ⱥ���ɵ�
    {
        return rightRotate(root);
    }
    //rightright
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
    {
        return leftRotate(root);
    }
    // left right
    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    //right left
    if (balance < -1 && getBalanceFactor(root->right)>0)
    {
        root->right = rightRotate(root->right);
        leftRotate(root);
    }
    //ɾ���ڵ����Ȼ��ƽ��ģ�����Ҫ��ת
    return root;
}

