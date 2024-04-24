#include <iostream>
#include <cstring>

int main() {
    const char* str1 = "abc";
    char* str0 = new char[strlen(str1) + 1]; // Allocate memory for str0

    strcpy(str0, str1); // Copy the value of str1 to str0

    std::cout << str0 << std::endl; // Output: abc

    delete[] str0; // Don't forget to deallocate memory

    return 0;
}
#include <iostream>
#include <string>

int main() {
    const char* str1 = "abc";
    std::string str0 = str1;

    std::cout << str0 << std::endl; // Output: abc

    return 0;
}
