/*
Min-Heap Implementation in C++
A min-heap is a binary tree data structure where each parent node is less than or equal to its child nodes. This property allows for efficient retrieval of the minimum element, which is always located at the root of the tree. Min-heaps are commonly used in priority queues and heap sort algorithms.

In this implementation, we will create a MinHeap class that provides methods for inserting elements, removing the minimum element, and maintaining the heap property. The underlying data structure will be a vector to store the elements of the heap.

Key Operations:
1. insert(int value): This method adds a new value to the heap and ensures that the heap property is maintained by performing an "up-heap" operation.
2. removeMin(): This method removes and returns the minimum element (the root of the heap) and then restores the heap property by performing a "down-heap" operation.
3. getMin(): This method returns the minimum element without removing it from the heap.
4. size(): This method returns the number of elements currently in the heap.
5. isEmpty(): This method checks if the heap is empty.
The implementation will also include helper methods for maintaining the heap property, such as "up-heap" and "down-heap" operations, which will be used during insertion and removal of elements.

*/

#include <iostream>
#include <vector>
#include <stdexcept>

class MinHeap {
private:
    std::vector<int> heap;

    void upHeap(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void downHeap(int index) {
        int size = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }
            if (smallest != index) {
                std::swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        upHeap(heap.size() - 1);
    }
    
    int removeMin() {
        if (heap.empty()) {
            throw std::underflow_error("Heap is empty");
        }
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            downHeap(0);
        }
        return minValue;
    }

    int getMin() const {
        if (heap.empty()) {
            throw std::underflow_error("Heap is empty");
        }
        return heap[0];
    }

    int size() const {
        return heap.size();
    }

    bool isEmpty() const {
        return heap.empty();
    }
};
