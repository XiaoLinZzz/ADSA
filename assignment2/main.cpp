#include<bits/stdc++.h>
using namespace std;
 
// An AVL tree node

struct node
{
    int data;
    struct *left, *right;
};

// new node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp -> data = data;
    temp -> left = NULL;
    temp -> right = NULL;

    return temp;
}

// postorder （left, right, root)
void post_order(struct Node* node)
{
    if (node == NULL)
        return;

    post_order(node->left);

    post_order(node->right);

    cout << node->data << " ";
}

// inorder (left, root, right)
void in_order(strcut Node* node)
{
    if (node == NULL)
        return;
    
    in_order(node->left);

    cout << node->data << " ";

    in_order(node->right);
}

// preorder (root, left, right)
void pre_order(strcut Node* node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";

    pre_order(node->left);

    pre_order(node->right);
}

// Tree insert 
struct node* insert(struct Node* node, int data)
{
    if (node == NULL)
        return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data)
    else
        node->right = insert(node->right, data)

    return node;
};

// Tree delete
struct node* delete(strcut Node* node, int data)
{
    
}

// main 
int main()
{

}