#include <iostream>
#include <cstring>

int main() {
    char* str0 = nullptr;  // initialize str0 to nullptr
    const char* str1 = "abc";

    str0 = const_cast<char*>(str1); // use const_cast to convert const char* to char*

    std::cout << str0 << std::endl;  // expected output: abc

    return 0;
}
