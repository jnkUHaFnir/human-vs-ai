#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
  private:
    static const int MAX_SIZE = 100; // Define a maximum size for your string.
    char chars[MAX_SIZE];
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
using namespace std;

MyString1::MyString1(char chars[], int size)
{
    for (int i = 0; i < size; i++)
    {
        this->chars[i] = chars[i];
    }
    this->size = size;
}

MyString1 MyString1::append(MyString1 s)
{
    for (int i = size; i < size + s.length(); i++)
    {
        chars[i] = s.at(i - size);
    }
    size += s.length();
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
}

bool MyString1::empty()
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
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
    return -1; // Return -1 if the character is not found
}
#include <iostream>
#include "myString1.h"
using namespace std;

int main()
{
    MyString1 first("cat", 3);
    MyString1 second("dog", 3);
    cout << first.at(1) << " and " << second.at(1) << endl;
    first.append(second);
    cout << first.at(5) << endl;

    return 0;
}
