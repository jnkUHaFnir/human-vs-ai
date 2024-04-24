#include <iostream>
#include <cstring>

int main() {
    const char* str1 = "abc";
    
    // Allocate memory for str0 to hold a copy of str1
    char* str0 = new char[strlen(str1) + 1]; // +1 for null terminator
    
    strcpy(str0, str1); // Copy the contents of str1 to str0
    
    std::cout << str0 << std::endl; // Output: abc
    
    // Don't forget to free the memory allocated for str0
    delete[] str0;
    
    return 0;
}
