#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
private:
    char chars[100]; // Specify the size of chars array
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
    ~MyString1(); // Destructor declaration
};
#endif
#include "myString1.h"
#include <cstring>

using namespace std;

MyString1::MyString1(char chars[], int size)
{
    strcpy(this->chars, chars);
    this->size = size;
}

MyString1 MyString1::append(MyString1 s)
{
    for(int i = size, j = 0; j < s.length(); i++, j++) {
        chars[i] = s.at(j);
    }
    size += s.length();
    return *this;
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
    size = 0;
    memset(chars, 0, sizeof(chars)); // Set all elements to 0
}

bool MyString1::empty()
{
    return size == 0; // Check if size is equal to 0
}

int MyString1::find(char ch)
{
    for(int i = 0; i < size; i++) {
        if(chars[i] == ch) { // Use '==' for comparison
            return i;
        }
    }
    return -1; // Return -1 if character not found
}

MyString1::~MyString1()
{
    // You can add any cleanup code here
}
