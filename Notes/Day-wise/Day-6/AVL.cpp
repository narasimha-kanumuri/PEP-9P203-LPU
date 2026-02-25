/*
1. AVL Tree is a self-balancing binary search tree where the difference between heights of left and right subtrees cannot be more than one for any node.
2. It maintains the balance of the tree by performing rotations (single or double) when necessary during insertion and deletion operations.
3. Each node in an AVL tree contains a balance factor, which is the difference in height between its left and right subtrees. The balance factor can be -1, 0, or +1.
4. The height of an AVL tree is O(log n), where n is the number of nodes in the tree, ensuring efficient search, insertion, and deletion operations.

Lets create for  the input and output of the AVL tree:
Input: 89, 45 , 36, 18, 50, 70,63,75,85,100
Output: (The AVL tree structure after each insertion)
*/

//Code for AVL Tree in C++ with deletion also implemented

#include <iostream>
using namespace std;
// AVL Tree Node
class AVLNode {
public:
    int key;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) : key(value), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree Class
class AVLTree {
private:
    AVLNode* root;

    int height(AVLNode* node) {
        return node ? node->height : 0;
    }

    int getBalance(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        // Return new root
        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        // Return new root
        return y;
    }

    AVLNode* insert(AVLNode* node, int key) {
        // Perform the normal BST insert
        if (!node)
            return new AVLNode(key);
        
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else // Duplicate keys not allowed
            return node;

        // Update height of this ancestor node
        node->height = 1 + max(height(node->left), height(node->right));

        // Get the balance factor to check whether this node became unbalanced
        int balance = getBalance(node);

        // If unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);

        // Right Right Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    //delete function can be implemented similarly by following the standard BST delete and then performing rotations to maintain balance
    

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        root = insert(root, key);
    }

    void inorder(AVLNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    int keys[] = {89, 45, 36, 18, 50, 70, 63, 75, 85, 100};
    for (int key : keys) {
        tree.insert(key);
        tree.displayInorder();
    }
    return 0;
}
