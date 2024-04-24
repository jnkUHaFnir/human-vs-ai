#include <iostream>
#include <cstring>

int main() {
    char* str0;
    const char* str1 = "abc";
    
    // Allocating memory for str0 and copying str1 to str0
    str0 = new char[strlen(str1) + 1];
    strcpy(str0, str1);

    std::cout << str0 << std::endl; // Output: abc

    // Don't forget to free the memory when you're done with it
    delete[] str0;

    return 0;
}
