#include<bits/stdc++.h>
using namespace std;
 
// An AVL tree node
class Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N -> height;
}

// new node
Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 

    return(node);
}

// find node
int 


// Tree insert


// Tree delete

