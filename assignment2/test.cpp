#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
 
// An AVL tree node
class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    int height;
};

// new node
Node* newNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;

    return (temp);
}

// get height
int height(Node *node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

// right rotate
Node* right_rotate(Node *right)
{
    Node *left = right->left;
    Node *T2 = left->right;

    // do right roatate
    left->right = right;
    right->left = T2;

    // update heights
    right->height = max(height(right->left), height(right->right)) + 1;
    left->height = max(height(left->left), height(left->right)) + 1;

    return left;
}

// left rotate
Node* left_rotate(Node *left)
{
    Node *right = left->right;
    Node *T2 = right->left;

    // do left rotate
    right->left = left;
    left->right = T2;

    // update heights
    right->height = max(height(right->left), height(right->right)) + 1;
    left->height = max(height(left->left), height(left->right)) + 1;


    return right;
}

// get balance (0, 1 or -1)
int get_balance(Node *node)
{
    if (node == NULL)
        return 0;

    return height(node -> left) - height(node -> right); 
}

// insert node
Node* insert_node(Node *node, int data)
{
    if (node == NULL)
        return (newNode(data));

    if (data < node->data)
        node->left = insert_node(node->left, data);
    else if (data > node->data)
        node->right = insert_node(node->right, data);
    else    
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = get_balance(node);

    // left left
    if (balance > 1 && data < node->left->data)
        return right_rotate(node);

    // right right
    if (balance < -1 && data > node->right->data)
        return left_rotate(node);

    // left right
    if (balance > 1 && data > node->left->data) {
        node->left = left_rotate(node->left);

        return right_rotate(node);
    }

    // right left
    if (balance < -1 && data < node->right->data) {
        node->right = right_rotate(node->right);

        return left_rotate(node);
    }

    return node;
}

// delete node
/* 
Node* delete_node(Node *node, int data)
{
    if (node == NULL)
        return node;

    if (data < node->data)
        node->left = delete_node(node->left, data)
    else if (data > node->data)
        nodpe->right = delete_node(node->right, data)
    else    
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

}
*/

// postorder （left, right, root)
void post_order(struct Node* node)
{
    if (node != NULL)
    {
        post_order(node->left);
        post_order(node->right);
        cout << node->data << " ";
    }
}

// inorder (left, root, right)
void in_order(struct Node* node)
{
    if (node != NULL)
    {
        in_order(node->left);
        cout << node->data << " ";
        in_order(node->right);
    }
}

// preorder (root, left, right)
void pre_order(struct Node* node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        pre_order(node->left);
        pre_order(node->right);
    }
}

// main function
int main()
{
    
    Node *root = NULL;

    root = insert_node(root, 1);
    root = insert_node(root, 2);
    root = insert_node(root, 3);

    in_order(root);
}