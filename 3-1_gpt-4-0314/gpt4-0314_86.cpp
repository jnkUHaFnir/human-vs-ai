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
    MyString1 append(const MyString1 &s);
    char at(int index) const;
    int length() const;
    void clear();
    bool empty() const;
    int find(char ch) const;
};
#endif
#include "myString1.h"
#include <cstring>
using namespace std;

MyString1::MyString1(const char chars[], int size)
{
    this->chars = new char[size];
    memcpy(this->chars, chars, size);
    this->size = size;
}

MyString1 MyString1::append(const MyString1 &s)
{
    char *newChars = new char(size + s.length());
    memcpy(newChars, chars, size);
    memcpy(newChars + size, s.chars, s.size);

    MyString1 result(newChars, size + s.size);
    delete[] newChars;
    return result;
}

char MyString1::at(int index) const
{
    return chars[index];
}

int MyString1::length() const
{
    return size;
}

void MyString1::clear()
{
    size = 0;
}

bool MyString1::empty() const
{
    return size == 0;
}

int MyString1::find(char ch) const
{
    for (int i = 0; i < size; i++)
        if (chars[i] == ch)
            return i;
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
    first = first.append(second);
    cout << first.at(6) << endl;

    return 0;
}
