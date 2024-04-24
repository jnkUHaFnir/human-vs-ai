#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
private:
    char* chars;
    size_t size;

public:
    MyString1();
    MyString1(char* chars, size_t size);
    MyString1 append(MyString1 s);
    char at(size_t index);
    size_t length();
    void clear();
    bool empty();
    size_t find(char ch);
};
#endif
#include "myString1.h"
#include <cstring> // Include for strcpy

MyString1::MyString1(char* chars, size_t size)
{
    this->chars = new char[size + 1]; // +1 for null terminator
    std::strcpy(this->chars, chars);
    this->size = size;
}

MyString1 MyString1::append(MyString1 s)
{
    // Implement append logic here
}

char MyString1::at(size_t index)
{
    return chars[index];
}

size_t MyString1::length()
{
    return size;
}

void MyString1::clear()
{
    size = 0;
    delete[] chars;
    chars = nullptr;
}

bool MyString1::empty()
{
    return (size == 0);
}

size_t MyString1::find(char ch)
{
    // Implement find logic here
}
