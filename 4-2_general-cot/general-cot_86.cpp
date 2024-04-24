#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1 {
private:
    char* chars;
    int size;
public:
    MyString1();
    MyString1(const char* chars, int size);
    void append(const MyString1& s);
    char at(int index);
    int length();
    void clear();
    bool empty();
    int find(char ch);
};

#endif
#include "myString1.h"
#include <cstring> // For strlen()

MyString1::MyString1() : chars(nullptr), size(0) {}

MyString1::MyString1(const char* chars, int size) : size(size) {
    this->chars = new char[size + 1]; // Plus one for null-terminator
    std::strncpy(this->chars, chars, size);
    this->chars[size] = '\0'; // Null-terminate the string
}

void MyString1::append(const MyString1& s) {
    char* newChars = new char[size + s.length() + 1]; // Plus one for null-terminator
    std::strcpy(newChars, chars);
    std::strcat(newChars, s.chars);
    
    delete[] chars; // Free the old memory
    chars = newChars;
    size += s.length();
}

char MyString1::at(int index) {
    if (index >= 0 && index < size) {
        return chars[index];
    }
    // Handle out-of-bounds access, you may throw an exception or return a default value
    return '\0';
}

int MyString1::length() {
    return size;
}

void MyString1::clear() {
    delete[] chars;
    size = 0;
    chars = nullptr;
}

bool MyString1::empty() {
    return (chars == nullptr || size == 0);
}

int MyString1::find(char ch) {
    for (int i = 0; i < size; i++) {
        if (chars[i] == ch) {
            return i;
        }
    }
    return -1; // Return -1 if not found
}
