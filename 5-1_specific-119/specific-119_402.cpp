#include <iostream>
#include <cstring>

const char* str1 = "abc";
char str0[4]; // Allocate memory for str0, including space for null terminator

int main() {
    // Using strcpy_s
    strcpy_s(str0, sizeof(str0), str1);

    std::cout << str0 << std::endl; // This will print: abc

    return 0;
}
#include <iostream>
#include <cstring>

const char* str1 = "abc";
char* str0;

int main() {
    str0 = new char[strlen(str1) + 1]; // Allocate memory for str0
    strcpy_s(str0, strlen(str1) + 1, str1);

    std::cout << str0 << std::endl; // This will print: abc

    delete[] str0; // Free the dynamically allocated memory

    return 0;
}
