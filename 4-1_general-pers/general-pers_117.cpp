#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1 {
private:
   char* chars;
   int size;
public:
   MyString1();
   MyString1(char* chars, int size);
   MyString1 append(MyString1 s);
   char at(int index);
   int length();
   void clear();
   bool empty();
   int find(char ch);
};
#endif
#include "myString1.h"
#include <cstring> // for strcpy

MyString1::MyString1(char* chars, int size) {
    this->chars = new char[size];
    strcpy(this->chars, chars);
    this->size = size;
}

MyString1 MyString1::append(MyString1 s) {
    char* temp = new char[size + s.size];
    strcpy(temp, chars);
    strcat(temp, s.chars);
    MyString1 result(temp, size + s.size);
    delete[] temp;
    return result;
}

char MyString1::at(int index) {
    return chars[index];
}

int MyString1::length() {
    return size;
}

void MyString1::clear() {
    delete[] chars;
    size = 0;
}

bool MyString1::empty() {
    return (size == 0);
}

int MyString1::find(char ch) {
    for (int i = 0; i < size; i++) {
        if (chars[i] == ch) {
            return i;
        }
    }
    return -1; // Character not found
}
