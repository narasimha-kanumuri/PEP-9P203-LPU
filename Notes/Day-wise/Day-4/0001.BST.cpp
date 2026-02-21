/*
Binary Search Tree (BST) Implementation in C++
1. Node Structure:
   - Each node contains a value, a pointer to the left child, and a pointer to the right child.
2. Insertion:
   - To insert a value, start at the root and compare the value with the current node's value.
   - If the value is smaller, move to the left child; if larger, move to the right child.
   - Repeat this process until you find an appropriate null position to insert the new node.
3. Search:
   - Similar to insertion, start at the root and compare the target value with the current node
    - If the value matches, return true; if smaller, move to the left child; if larger, move to the right child.
    - If you reach a null node, the value is not found in the tree.
4. Deletion:
   - To delete a node, first find the node to be deleted.
    - If the node has no children, simply remove it.
    - If the node has one child, replace the node with its child.
    - If the node has two children, find the in-order successor (the smallest value in the right subtree), replace the node's value with the successor's value, and then delete the successor node.
5. Traversal:
   - In-order Traversal: Visit the left subtree, the current node, and then the
    right subtree. This will return the values in sorted order.
    - Pre-order Traversal: Visit the current node, then the left subtree, and finally the right subtree.
    - Post-order Traversal: Visit the left subtree, the right subtree, and then the current node.

*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    void insert(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        } else if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }
    
    void preOrder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(Node* node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }
    
public:
    BST() : root(nullptr) {}

    void insert(int value) {
        insert(root, value);
    }

    bool search(int value) {
        return search(root, value);
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }

    void preOrder() {
        preOrder(root);
        cout << endl;
    }

    void postOrder() {
        postOrder(root);
        cout << endl;
    }
};