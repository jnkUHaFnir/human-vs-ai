#include <iostream>
#include <cstring>

int main() {
    const char* str1 = "abc";
    
    // Allocate memory for str0 
    char* str0 = new char[strlen(str1) + 1]; // +1 for null terminator
    
    // Copy the content of str1 to str0
    strcpy(str0, str1);
    
    std::cout << str0 << std::endl; // Output: abc
    
    // Don't forget to free the allocated memory when done
    delete[] str0;
    
    return 0;
}
