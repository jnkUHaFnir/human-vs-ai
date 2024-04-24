#include <iostream>
#include <cstring>

int main() {
    const char* str1 = "abc";
    char* str0 = new char[strlen(str1) + 1]; // +1 for null terminator

    strcpy(str0, str1);

    std::cout << str0 << std::endl;

    delete[] str0; // Don't forget to free the memory

    return 0;
}
