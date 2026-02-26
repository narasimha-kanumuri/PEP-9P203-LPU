/* 
Morris Traversal is a tree traversal algorithm that does not use recursion or a stack. It is used to traverse a binary tree in-order with O(1) space complexity. The idea is to make use of the threaded binary tree concept, where we temporarily modify the tree's structure to create links to the inorder predecessor.
In Morris Traversal, we follow these steps:
1. Initialize the current node as the root.
2. While the current node is not null:
   a. If the current node has no left child, visit the current node and move to the right child.
   b. If the current node has a left child, find the rightmost node in the left subtree (predecessor). If the rightmost node's right child is null, set it to point to the current node and move to the left child. If the rightmost node's right child is already pointing to the current node, it means we have visited all nodes in the left subtree. Set it back to null, visit the current node, and move to the right child.
The time complexity of Morris Traversal is O(n) in the worst case, where n is the number of nodes in the tree, because we may have to visit all nodes. However, the space complexity is O(1) since we are not using any additional data structures for traversal.
*/

// C++ program to demonstrate Morris Traversal
#include <bits/stdc++.h>
using namespace std;

// A binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to perform Morris Traversal
void morrisTraversal(Node* root) {
    Node* curr = root;

    while (curr != NULL) {
        if (curr->left == NULL) {
            // Visit the current node
            cout << curr->data << " ";
            // Move to the right child
            curr = curr->right;
        } else {
            // Find the rightmost node in the left subtree (predecessor)
            Node* predecessor = curr->left;
            while (predecessor->right != NULL && predecessor->right != curr) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
                // Make the current node as the right child of its predecessor
                predecessor->right = curr;
                // Move to the left child
                curr = curr->left;
            } else {
                // Revert the changes made in the tree structure
                predecessor->right = NULL;
                // Visit the current node
                cout << curr->data << " ";
                // Move to the right child
                curr = curr->right;
            }
        }
    }
}