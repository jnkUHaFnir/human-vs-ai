#include<iostream>

int main(){
    const char* str1 = "abc";
    char* str0;            
    str0 = new char[strlen(str1) + 1];     // +1 for the null-terminator
    strcpy(str0, str1);
    std::cout << str0 << std::endl;  // prints: abc

    delete [] str0;    // don't forget to deallocate the allocated memory
    return 0;
}
