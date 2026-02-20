/*
Reverse entire string(input) using C++ STL reverse function.
Reverse entire string(input) without using any built-in function.
Reverse each word in the string(input) without using any built-in function, and no extra space should be used.

Sample Input: "Hello World"
Sample Output: "dlroW olleH"
*/

#include <iostream>
#include <algorithm>
#include <string>

// Function to reverse a string using STL reverse function
std::string reverseStringSTL(const std::string& input) {
    std::string reversed = input; // Create a copy of the input string
    std::reverse(reversed.begin(), reversed.end()); // Reverse the string using STL
    return reversed;
}

// Function to reverse a string without using any built-in function
std::string reverseStringManual(const std::string& input) {
    std::string reversed; // Create an empty string to store the reversed result
    for (int i = input.length() - 1; i >= 0; --i) { // Iterate through the input string in reverse order
        reversed += input[i]; // Append each character to the reversed string
    }
    return reversed;
}

// Function to reverse each word in the string without using any built-in function and no extra space
void reverseWordsInPlace(std::string& input) {
    int start = 0; // Start index of a word
    for (int end = 0; end <= input.length(); ++end) { // Iterate through the string
        if (end == input.length()) { // If we reach the end of a word
            // Reverse the word in place
            int left = start, right = end - 1; // Set left and right pointers
            while (left < right) { // Swap characters until the pointers meet
                std::swap(input[left], input[right]);
                ++left;
                --right;
            }
            start = end + 1; // Move to the start of the next word
        }
    }
}