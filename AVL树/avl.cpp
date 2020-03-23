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
// BST的标准插入操作
   //第一个节点
    if (node == NULL)
        return (newNode(key));
    // 先处理左或者右边的子节点，再考虑本节点的(从下到上遍历检查是否是平衡的
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if(key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else// BST树中不能有相同的键值
    {
        return node;
    }
// 更新本节点的高度
    node->height = 1 + max(height(node->left), height(node->right));
// 计算balance factor 并且去检查这个节点是否是平衡的
    int balancefactor = getBalanceFactor(node);

// 四种情况分别讨论
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
    return curNode;//找到了  in order successor
}

Node* deleteNode(Node* root, int key)
{
    //数的根为空节点
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
        // 被删除的节点有至多一个子节点
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
        // 被删除的节点有两个子节点
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

    // Update 当前节点的高度
    root->height = max(height(root->left), height(root->right)) + 1;

    // 计算balance factor
    int balance = getBalanceFactor(root);

    // 根据计算结果旋转平衡
        //left left
    if (balance > 1 && getBalanceFactor(root->left) >= 0)// 注意这里的等于号，当有多条路径都可以实现balance > 1时，优先考虑left left，因为这个等号造成的
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
    //删除节点后依然是平衡的，不需要旋转
    return root;
}

