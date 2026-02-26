/*
BST Implementation to find kth smallest element in the BST using Morris Traversal
*/

/*
Morris Traversal is a tree traversal algorithm that uses O(1) space complexity by modifying the tree structure during the traversal. It allows us to traverse the tree without using a stack or recursion.
To find the kth smallest element using Morris Traversal, we can follow these steps:
1. Initialize a count variable to keep track of the number of nodes visited.
2. Start from the root node and repeat the following until we find the kth smallest element:
   a. If the current node has no left child, visit the current node and increment the count. If the count equals k, return the value of the current node. Move to the right child.
   b. If the current node has a left child, find the rightmost node in the left subtree (predecessor). If the rightmost node's right child is null, set it to point to the current node and move to the left child. If the rightmost node's right child is already pointing to the current node, it means we have visited all nodes in the left subtree. Set it back to null, visit the current node, and increment the count. If the count equals k, return the value of the current node. Move to the right child.
The time complexity of this approach is O(n) in the worst case, where n is the number of nodes in the tree, because we may have to visit all nodes to find the kth smallest element. However, the space complexity is O(1) since we are not using any additional data structures for traversal.
*/