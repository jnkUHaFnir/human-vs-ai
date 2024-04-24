#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
private:
    char *chars;
    int size;

public:
    MyString1();
    MyString1(const char *chars, int size);
    MyString1 append(const MyString1& s);
    char at(int index);
    int length();
    void clear();
    bool empty();
    int find(char ch);
};

#endif
#include "myString1.h"
#include <cstring>
#include <iostream>

MyString1::MyString1(const char *chars, int size)
{
    this->size = size;
    this->chars = new char[size + 1]; // +1 for null terminator
    std::strcpy(this->chars, chars); // copy contents
}

MyString1 MyString1::append(const MyString1& s)
{
    char *temp = new char[size + s.length() + 1];
    std::strcpy(temp, chars);
    std::strcat(temp, s.chars);

    MyString1 result(temp, size + s.length());
    delete[] temp;

    return result;
}

char MyString1::at(int index)
{
    if (index >= 0 && index < size)
    {
        return chars[index];
    }
    return '\0'; // or throw an exception
}

int MyString1::length()
{
    return size;
}

void MyString1::clear()
{
    delete[] chars;
    size = 0;
    chars = new char[1];
    chars[0] = '\0';
}

bool MyString1::empty()
{
    return (size == 0);
}

int MyString1::find(char ch)
{
    for (int i = 0; i < size; i++)
    {
        if (chars[i] == ch)
        {
            return i;
        }
    }
    return -1; // not found
}
