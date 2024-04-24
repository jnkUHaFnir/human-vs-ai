#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1 {
private:
    char* chars;
    int size;

public:
    MyString1();
    MyString1(const char* chars, int size);
    MyString1 append(MyString1 s);
    char at(int index);
    int length();
    void clear();
    bool empty();
    int find(char ch);
};

#endif
#include "myString1.h"
#include <cstring>

MyString1::MyString1() : size(0), chars(nullptr) {}

MyString1::MyString1(const char* chars, int size) : size(size) {
    this->chars = new char[size];
    std::memcpy(this->chars, chars, size);
}

MyString1 MyString1::append(MyString1 s) {
    char* newChars = new char[size + s.size];
    std::memcpy(newChars, chars, size);
    std::memcpy(newChars + size, s.chars, s.size);
    delete[] chars;
    chars = newChars;
    size += s.size;
    return *this;
}

char MyString1::at(int index) {
    return chars[index];
}

int MyString1::length() {
    return size;
}

void MyString1::clear() {
    delete[] chars;
    chars = nullptr;
    size = 0;
}

bool MyString1::empty() {
    return (size == 0 || chars[0] == '\0');
}

int MyString1::find(char ch) {
    for (int i = 0; i < size; i++) {
        if (chars[i] == ch) {
            return i;
        }
    }
    return -1;
}
#include <iostream>
#include "myString1.h"
using namespace std;

int main() {
    MyString1 first("cat", 3);
    MyString1 second("dog", 3);
    cout << first.at(1) << " and " << second.at(1) << endl;
    first.append(second);
    cout << first.at(6) << endl;

    return 0;
}
