/*
BST Implementation to find kth smallest element in the BST
*/

/*
In a Binary Search Tree (BST), the in-order traversal of the tree gives the nodes in sorted order. To find the kth smallest element, we can perform an in-order traversal and keep track of the count of nodes visited. When the count reaches k, we have found our kth smallest element.

The time complexity of this approach is O(h + k), where h is the height of the tree and k is the number of nodes visited to find the kth smallest element. In the worst case, when the tree is skewed, the time complexity can be O(n) where n is the number of nodes in the tree.
*/

/// C++ program to find the kth smallest element in a BST
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

// Function to find the kth smallest element in the BST
int kthSmallest(Node* root, int k) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {
        // Traverse the left subtree
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        // Visit the current node
        curr = st.top();
        st.pop();
        k--;

        // If we have found the kth smallest element
        if (k == 0) {
            return curr->data;
        }

        // Traverse the right subtree
        curr = curr->right;
    }

    // If k is larger than the number of nodes in the tree
    return -1; // or throw an exception
}