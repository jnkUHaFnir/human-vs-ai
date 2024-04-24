#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
private:
    char* chars;
    int size;

public:
    MyString1();
    MyString1(char chars[], int size);
    MyString1& append(MyString1 s);
    char at(int index);
    int length();
    void clear();
    bool empty();
    int find(char ch);
};
#endif
#include "myString1.h"
#include <cstring>

MyString1::MyString1(char chars[], int size)
{
    this->size = size;
    this->chars = new char[size + 1]; // +1 for null termination
    std::strcpy(this->chars, chars);
}

MyString1& MyString1::append(MyString1 s)
{
    int new_size = size + s.length();
    char* new_chars = new char[new_size + 1]; // +1 for null termination
    std::strcpy(new_chars, chars);
    std::strcpy(new_chars + size, s.chars);
    
    delete[] chars;
    chars = new_chars;
    size = new_size;

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

    delete[] chars;
    chars = new char[1];
    chars[0] = '\0';
}

bool MyString1::empty()
{
    return size == 0;
}

int MyString1::find(char ch)
{
    for (int i = 0; i < size; i++)
    {
        if (chars[i] == ch)
            return i;
    }
    
    return -1; // Return -1 if the character is not found
}
#include <iostream>
#include "myString1.h"
using namespace std;

int main()
{
    MyString1 first("cat", 3); // Adjust the size to match the string length
    MyString1 second("dog", 3); // Adjust the size to match the string length

    cout << first.at(1) << " and " << second.at(1) << endl;
    first.append(second);
    cout << first.at(6) << endl; // Note: Index starts from 0

    return 0;
}
