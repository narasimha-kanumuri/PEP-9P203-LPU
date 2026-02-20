/*
Replace all occurrences of a substring in a string with another substring.
Make sure to handle cases where the substring to be replaced is not found, and cases where the replacement substring is longer or shorter than the original substring.

ANother function for same, without using built-in functions:
*/

#include <iostream>
#include <string>

// Function to replace all occurrences of a substring in a string with another substring
void replaceSubstring(std::string& str, const std::string& oldSub, const std::string& newSub) {
    size_t pos = 0;
    while ((pos = str.find(oldSub, pos)) != std::string::npos) {
        str.replace(pos, oldSub.length(), newSub);
        pos += newSub.length();
    }
}

// Function to replace all occurrences of a substring in a string with another substring without using built-in functions
void replaceSubstringManual(std::string& str, const std::string& oldSub, const std::string& newSub) {
    std::string result; // Create a new string to store the result
    size_t i = 0;
    while (i < str.length()) {
        if (str.substr(i, oldSub.length()) == oldSub) { // Check if the substring matches
            result += newSub; // Append the new substring to the result
            i += oldSub.length(); // Move the index past the old substring
        } else {
            result += str[i]; // Append the current character to the result
            ++i; // Move to the next character
        }
    }
    str = result; // Update the original string with the modified result
}