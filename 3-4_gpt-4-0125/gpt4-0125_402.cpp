#include <iostream> // For std::cout
#include <cstring>  // For strcpy and strlen

int main() {
    char* str0;
    const char* str1 = "abc";

    // Allocate memory for str0. +1 for the null terminator.
    str0 = new char[strlen(str1) + 1]; 

    // Now you can safely copy str1 to str0.
    strcpy(str0, str1);

    // This prints "abc"
    std::cout << str0 << std::endl;

    // Don't forget to free the allocated memory!
    delete[] str0;
    
    return 0;
}
