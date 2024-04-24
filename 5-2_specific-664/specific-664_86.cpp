#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
private:
    static const int MAX_SIZE = 100; // Define a maximum size for the string
    char chars[MAX_SIZE];
    int size;

public:
    MyString1();
    MyString1(char chars[], int size);
    MyString1 append(const MyString1 &s);
    char at(int index);
    int length();
    void clear();
    bool empty();
    int find(char ch);
    ~MyString1(); // Destructor to release any allocated resources
};
#endif
#include "myString1.h"

MyString1::MyString1(char chars[], int size)
{
    this->size = size;
    strncpy(this->chars, chars, size); // Copy at most 'size' characters to 'chars'
    this->chars[size] = '\0'; // Ensure the char array is null-terminated
}

MyString1 MyString1::append(const MyString1 &s)
{
    for(int i = 0; i < s.size && size + i < MAX_SIZE; i++)
    {
        chars[size + i] = s.at(i);
    }
    size += s.size;
    chars[size] = '\0'; // Ensure the whole string is null-terminated
    return *this; // Return the updated string
}

char MyString1::at(int index)
{
    if(index >= 0 && index < size)
    {
        return chars[index];
    }
    return '\0'; // Return null character for out-of-bounds access
}

int MyString1::length()
{
    return size;
}

void MyString1::clear()
{
    size = 0;
    chars[0] = '\0'; // Clear the string by null-terminating it
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
    return -1; // Return -1 if the character is not found
}

MyString1::~MyString1()
{
    // Add any necessary clean-up code here
}
