#include "avl.h"
using namespace std;
void test_insert()
{
    Node* root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);

    preOrder(root);
    std::cout << std::endl;
    inOrder(root);

}
void test_delete()
{
    Node *root = NULL;

    /* Constructing tree given in
    the above figure */
    root = insertNode(root, 9);
    root = insertNode(root, 5);
    root = insertNode(root, 10);
    root = insertNode(root, 0);
    root = insertNode(root, 6);
    root = insertNode(root, 11);
    root = insertNode(root, -1);
    root = insertNode(root, 1);
    root = insertNode(root, 2);
    cout << "Preorder traversal of the "
        "constructed AVL tree is \n";
    preOrder(root);

    root = deleteNode(root, 10);
    cout << "\nPreorder traversal after"
        << " deletion of 10 \n";
    preOrder(root);

}

int main()
{
    test_delete();
}