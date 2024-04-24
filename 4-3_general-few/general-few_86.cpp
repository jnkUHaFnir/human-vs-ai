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
    MyString1 append(MyString1& s);
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
    this->chars = new char[size];
    for (int i = 0; i < size; i++)
    {
        this->chars[i] = chars[i];
    }
}

MyString1 MyString1::append(MyString1& s)
{
    MyString1 result;
    result.size = size + s.size;
    result.chars = new char[result.size];

    int i;
    for (i = 0; i < size; i++)
    {
        result.chars[i] = chars[i];
    }

    for (int j = 0; j < s.size; j++)
    {
        result.chars[i + j] = s.chars[j];
    }

    return result;
}

char MyString1::at(int index)
{
    if (index >= 0 && index < size)
    {
        return chars[index];
    }
    return '\0';
}

int MyString1::length()
{
    return size;
}

void MyString1::clear()
{
    delete[] chars;
    size = 0;
    chars = nullptr;
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
        {
            return i;
        }
    }
    return -1;
}
#include <iostream>
#include "myString1.h"

int main()
{
    char cat[] = "cat";
    char dog[] = "dog";

    MyString1 first(cat, 4);
    MyString1 second(dog, 4);

    std::cout << first.at(1) << " and " << second.at(1) << std::endl;
    
    MyString1 result = first.append(second);
    
    std::cout << result.at(6) << std::endl;

    return 0;
}
