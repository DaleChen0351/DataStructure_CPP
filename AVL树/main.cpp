#include "avl.h"
using namespace std;
void test_insert()
{
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    preOrder(root);
    std::cout << std::endl;
    inOrder(root);

}
void test_delete()
{
    Node *root = NULL;

    /* Constructing tree given in
    the above figure */
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
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
    test_insert();
}