/*
Complete code for BST insertion and deletion in C++14

deletions in BST can be categorized into three cases:
1. Deleting a leaf node (a node with no children)
2. Deleting a node with one child (either left or right)
3. Deleting a node with two children (both left and right)
In the case of deleting a node with two children, we need to find the in-order successor (the smallest node in the right subtree) or the in-order predecessor (the largest node in the left subtree) to replace the deleted node. This ensures that the properties of the BST are maintained after deletion.

Main: INput:
2 5 6 7 9 9.5 10 12 15 18 20 30 50 60 70 80 90 100 110 120
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

    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) return node;

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the in-order successor
            Node* temp = minValueNode(node->right);
            node->data = temp->data; // Copy the in-order successor's content to this node
            node->right = deleteNode(node->right, temp->data); // Delete the in-order successor
        }
        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        insert(root, value);
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }

    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void display() {
        inorder(root);
        cout << endl;
    }

};

int main() {
    BST bst;
    int values[] = {2, 5, 6, 7, 9, 9.5, 10, 12, 15, 18, 20, 30, 50, 60, 70, 80, 90, 100, 110, 120};
    for (int value : values) {
        bst.insert(value);
    }

    cout << "In-order traversal of the BST: ";
    bst.display();

    // Deleting a node with two children
    bst.deleteNode(10);
    cout << "In-order traversal after deleting node with value 10: ";
    bst.display();

    // Deleting a node with one child
    bst.deleteNode(9);
    cout << "In-order traversal after deleting node with value 9: ";
    bst.display();

    // Deleting a leaf node
    bst.deleteNode(2);
    cout << "In-order traversal after deleting node with value 2: ";
    bst.display();

    return 0;
}

