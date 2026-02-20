/*
Reverse each word of the string(input) without using any built-in function, and no extra space should be used.

Sample Input: "Hello World"
Sample Output: "olleH dlroW"
*/

#include <iostream>
#include <string>
// Function to reverse each word in the string without using any built-in function and no extra space
void reverseWordsInPlace(std::string& input) {
    int start = 0; // Start index of a word
    for (int end = 0; end <= input.length(); ++end) { // Iterate through the string
        if (end == input.length() || input[end] == ' ') { // If we reach the end of a word
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