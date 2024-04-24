// myString1.h
#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
private:
    char chars[100]; // Fixed size array as an example
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
// myString1.cpp
#include "myString1.h"
#include <cstring> // For strcpy

MyString1::MyString1(char chars[], int size)
{
    strcpy(this->chars, chars); // Copy characters from input array to member array
    this->size = size;
}

MyString1& MyString1::append(MyString1 s)
{
    for(int i = size, j = 0; j < s.length(); i++, j++) {
        chars[i] = s.at(j);
    }
    size += s.length();
    return *this;
}

// Implement other member functions as needed
// testMyString1.cpp
#include <iostream>
#include "myString1.h"
using namespace std;

int main()
{
    MyString1 first("cat", 3);
    MyString1 second("dog", 3);
    
    cout << first.at(1) << " and " << second.at(1) << endl;
    first.append(second);
    cout << first.at(6) << endl;

    return 0;
}
