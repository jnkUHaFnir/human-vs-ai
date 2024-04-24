#include <iostream>

int main() {
    char data[] = {0, 0, 0, 0, 'H', 'e', 'l', 'l', 'o', 0, 'W', 'o', 'r', 'l', 'd', 0, '!', 0};

    int numIntegers = 2;
    int offset = numIntegers * sizeof(int);

    char* ptr = data + offset; // start from byte 8

    while (*ptr != '\0') {
        std::string token(ptr); // construct a string from current position
        std::cout << "Token: " << token << std::endl;
        
        ptr += token.length() + 1; // move the pointer to the next token
    }

    return 0;
}
