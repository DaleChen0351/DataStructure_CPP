#pragma once
#include <iostream>


class Node
{
public:
    int key;
    Node* left;
    Node* right;
    int height;
};

int height(Node* n);

int max(int a, int b);

Node* newNode(int key);

Node* rightRotate(Node* y);

Node* leftRotate(Node* x);

int getBalanceFactor(Node* n);

Node* minValueNode(Node* node);

Node* insertNode(Node* node, int key);

Node* deleteNode(Node* node, int key);

void preOrder(Node* root);

void inOrder(Node* root);





