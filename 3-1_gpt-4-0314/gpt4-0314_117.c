#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1 {
private:
    // Changed 'chars[]' to 'char *chars'
    char *chars;
    int size;
public:
    MyString1();
    MyString1(char *chars, int size); // Changed 'char chars[]' to 'char *chars'
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

MyString1::MyString1(char *chars, int size) // Changed 'char chars[]' to 'char *chars'
{
    // Fixed assignment
    this->chars = chars;
    this->size = size;
}
MyString1 MyString1::append(MyString1 s)
{
    // Added '&' to 's.length'
    for (int i = size; i > size - s.length(); i--)
        chars[i] = s.at(i - size);
    // Missing return statement
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
}
bool MyString1::empty()
{
    if (size == 0) // Changed 'if(chars[])' to 'if (size == 0)'
        return true;
    else
        return false;
}
int MyString1::find(char ch)
{
    for (int i = 0; i < size; i++)
        if (chars[i] == ch) // Changed '=' to '=='
            return i;
    return -1; // Added return statement for case when character not found
}
#include <iostream>
#include "myString1.h"
using namespace std;

int main()
{
    char data1[] = "cat";
    char data2[] = "dog";
    // Changed to pass 'data1' and 'data2'
    MyString1 first(data1, 4);
    MyString1 second(data2, 4);
    cout << first.at(1) << " and " << second.at(1) << endl;
    first.append(second);
    cout << first.at(6) << endl;

    return 0;
}
a and o
d
