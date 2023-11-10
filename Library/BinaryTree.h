#include <iostream>
using namespace std;

/**
 * @brief Tree node consisting of left and right children with a value
 * 
 */
struct Node{
    Node *left = nullptr, *right = nullptr;
    int val;

    Node(int val){
        this->val = val;
    }
};


/**
 * @brief Binary tree containing nodes in a tree-like structure with modules
 * 
 */
class BinaryTree{
    public:
        Node *root = nullptr;
        void insertNode(Node *, int);
        void preOrder(Node *);
        void inOrder(Node *);
        void postOrder(Node *);
};



/**
 * @brief Inserts new node at the Binary Tree
 * 
 * @param temp: tree node referenced
 * @param val: value to insert to the tree
 */
void BinaryTree::insertNode(Node *temp, int val){
    if(!root){
        root = new Node(val);
    } else {
        if(val <= temp->val){
            if(temp->left){
                insertNode(temp->left, val);
            } else {
                temp->left = new Node(val);
            }
        } else {
            if(temp->right){
                insertNode(temp->right, val);
            } else {
                temp->right = new Node(val); 
            }
        }
    } 
}



/**
 * @brief Prints all tree nodes using pre-order method
 * 
 * @param temp: tree node referenced
 */
void BinaryTree::preOrder(Node *temp){
    if(temp){
        cout << temp->val << " ";
        preOrder(temp->left);
        preOrder(temp->right);
    }
}



/**
 * @brief Prints all tree nodes using in-order method
 * 
 * @param temp: tree node referenced
 */
void BinaryTree::inOrder(Node *temp){
    if(temp){
        inOrder(temp->left);
        cout << temp->val << " ";
        inOrder(temp->right);
    } 
}



void BinaryTree::postOrder(Node *temp){
    if(temp){
        postOrder(temp->left);
        postOrder(temp->right);
        cout << temp->val << " ";
    }
}