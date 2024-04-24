#include <iostream>
#include <cstring>
#include <string>

int main() {
    char* str0;
    const char* str1 = "abc";

    // Allocate space for str0, including space for the null terminator
    str0 = new char[strlen(str1) + 1];

    // Copy str1 into str0
    strcpy(str0, str1);

    std::cout << str0 << std::endl;  // expected output: abc

    // Don't forget to delete[] the memory allocated with new[]
    delete[] str0;

    return 0;
}
abc
const char* str0 = str1;
