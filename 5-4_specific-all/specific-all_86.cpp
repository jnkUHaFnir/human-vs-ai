// myString1.h
#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
private:
    char *chars;
    int size;

public:
    MyString1();
    MyString1(const char chars[], int size);
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

MyString1::MyString1(const char chars[], int size)
{
    this->chars = new char[size + 1]; // +1 for null terminator
    strcpy(this->chars, chars);
    this->size = size;
}

MyString1 MyString1::append(MyString1 s)
{
    char *newChars = new char[size + s.length() + 1];
    strcpy(newChars, chars);
    strcpy(newChars + size, s.chars);
    
    MyString1 result(newChars, size + s.length());
    delete[] newChars;

    return result;
}

char MyString1::at(int index)
{
    return chars[index];
}

int MyString1::length()
{
    return size;
}

void MyString1::clear()
{
    delete[] chars;
    chars = new char[1];
    chars[0] = '\0';
    size = 0;
}

bool MyString1::empty()
{
    return size == 0;
}

int MyString1::find(char ch)
{
    for(int i = 0; i < size; i++)
    {
        if(chars[i] == ch)
        {
            return i;
        }
    }
    return -1; // for not found
}

// testMyString1.cpp
#include <iostream>
#include "myString1.h"
using namespace std;

int main()
{
    MyString1 first("cat", 3); // Change size to 3
    MyString1 second("dog", 3); // Change size to 3
    cout << first.at(1) << " and " << second.at(1) << endl;
    MyString1 result = first.append(second);
    cout << result.at(6) << endl;

    return 0;
}
