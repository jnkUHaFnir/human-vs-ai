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
    MyString1 append(MyString1 s);
    char at(int index);
    int length();
    void clear();
    bool empty();
    int find(char ch);
};
#endif
#include "myString1.h"

MyString1::MyString1(char chars[], int size)
{
    this->chars = new char[size];
    this->size = size;
    for(int i = 0; i < size; i++)
    {
        this->chars[i] = chars[i];
    }
}

MyString1 MyString1::append(MyString1 s)
{
    for(int i = 0; i < s.length(); i++)
    {
        chars[size + i] = s.at(i);
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
    delete[] chars;
    chars = nullptr;
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
    return -1;
}
#include <iostream>
#include "myString1.h"
using namespace std;

int main()
{
    MyString1 first("cat", 4);
    MyString1 second("dog", 4);
    cout << first.at(1) << " and " << second.at(1) << endl;
    first.append(second);
    cout << first.at(6) << endl;

    return 0;
}
