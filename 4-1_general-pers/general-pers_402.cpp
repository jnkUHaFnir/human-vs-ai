#include <iostream>
#include <cstring>

int main() {
    char* str0 = new char[strlen("abc") + 1]; // +1 for null terminator
    const char* str1 = "abc";

    strcpy(str0, str1);

    std::cout << str0 << std::endl;

    delete[] str0; // Don't forget to free the dynamically allocated memory

    return 0;
}
