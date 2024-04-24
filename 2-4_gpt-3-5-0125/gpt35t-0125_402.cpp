#include <iostream>
#include <cstring>

char* str0;
const char* str1 = "abc";

int main() {
    str0 = new char[strlen(str1) + 1]; // +1 for null terminator
    strcpy(str0, str1);
    
    std::cout << str0 << std::endl;
    
    delete[] str0; // don't forget to delete allocated memory
    
    return 0;
}
