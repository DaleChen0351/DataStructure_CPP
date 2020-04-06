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

int getBalanceFactor(Node * node)
{
    if (node == NULL)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node * minValueNode(Node * node)
{
    Node* curNode = node;
    // loop down to find the leftmost leaf.
    while (curNode->left != NULL)
    {
        curNode = curNode->left;
    }
    return curNode;//找到了  in order successor
}

Node* insertNode(Node* node, int key)
{
// standard BST insert operation
   // leaf node insert (first leaf node is root node )
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
    {
        node->left = insertNode(node->left, key);
    }
    else if(key > node->key)
    {
        node->right = insertNode(node->right, key);
    }
    else// BST树中不能有相同的键值
    {
        return node;
    }
// 更新本节点的高度
    node->height = 1 + max(height(node->left), height(node->right));
// 计算balance factor 
    int balancefactor = getBalanceFactor(node);

// check and fix the balance Factor
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
    // after insert node, the avl tree is still balanced, so re-balance not needed
    return node;
}

Node* deleteNode(Node* node, int key)
{
    //数的根为空节点
    if (node == NULL)
    {
        return node;
    }
    // find the postion of deleted node
    if (key < node->key)
    {
        node->left = deleteNode(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = deleteNode(node->right, key);
    }
    // find it ,delete it 
    else
    {
        // 被删除的节点有至多一个子节点
        if (node->left == NULL || node->right == NULL)
        {
            Node* temp = node->left ? node->left : node->right;
            // No child;
            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
            {
                *node = *temp;
            }
            free(temp);

        }
        // 被删除的节点有两个子节点
        else
        {
            // node with two children : Get the inorder
                // successor (smallest in the right subtree)  
            Node* temp = minValueNode(node->right);

            // Copy the inorder successor's  
            // data to this node  
            node->key = temp->key;

            // Delete the inorder successor  
            node->right = deleteNode(node->right,
                temp->key);
        }

    }

    // If the tree had only one node 
        // then return  
    if (node == NULL)
        return node;

    // Update 当前节点的高度
    node->height = max(height(node->left), height(node->right)) + 1;

    // 计算balance factor
    int balance = getBalanceFactor(node);

    // 根据计算结果旋转平衡
        //left left
    if (balance > 1 && getBalanceFactor(node->left) >= 0)// 注意这里的等于号，当有多条路径都可以实现balance > 1时，优先考虑left left，因为这个等号造成的
    {
        return rightRotate(node);
    }
    //rightright
    if (balance < -1 && getBalanceFactor(node->right) <= 0)
    {
        return leftRotate(node);
    }
    // left right
    if (balance > 1 && getBalanceFactor(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    //right left
    if (balance < -1 && getBalanceFactor(node->right)>0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    //删除节点后依然是平衡的，不需要旋转
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

