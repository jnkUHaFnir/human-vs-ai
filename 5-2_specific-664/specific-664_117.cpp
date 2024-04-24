// myString1.h
#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1 {
private:
    char *chars;
    int size;
public:
    MyString1();
    MyString1(char chars[], int size);
    MyString1 append(MyString1 s);
    char at(int index);
    int length();
    void clear();
    bool empty();
    int find(char ch);
};

#endif

// myString1.cpp
#include "myString1.h"
#include <cstring>
#include <iostream>
using namespace std;

MyString1::MyString1(char chars[], int size) {
    this->size = size;
    this->chars = new char[size+1];
    strcpy(this->chars, chars);
}

MyString1 MyString1::append(MyString1 s) {
    int newSize = size + s.length();
    char* newChars = new char[newSize + 1];
    strcpy(newChars, chars);
    strcat(newChars, s.chars);

    MyString1 result(newChars, newSize);
    delete[] newChars;

    return result;
}

char MyString1::at(int index) {
    if (index >= 0 && index < size) {
        return chars[index];
    } else {
        // Handle out-of-bounds access
        return '\0';
    }
}

int MyString1::length() {
    return size;
}

void MyString1::clear() {
    delete[] chars;
    size = 0;
    chars = new char[1];
    chars[0] = '\0';
}

bool MyString1::empty() {
    return size == 0;
}

int MyString1::find(char ch) {
    for (int i = 0; i < size; i++) {
        if (chars[i] == ch) {
            return i;
        }
    }
    return -1; // Return -1 if character not found
}

// testMyString1.cpp remains the same
