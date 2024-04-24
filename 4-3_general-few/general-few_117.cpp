// myString1.h
#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
  private:
   char chars[100]; // Specify a fixed size for the character array
   int size;
  public:
   MyString1();
   MyString1(char chars[], int size);
   void append(MyString1 s); // Change return type to void
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
using namespace std;

MyString1::MyString1(char chars[], int size)
{
  for(int i = 0; i < size; i++)
    this->chars[i] = chars[i];
  this->size = size;
}

void MyString1::append(MyString1 s)
{
  for(int i = 0; i < s.size; i++)
    chars[size + i] = s.chars[i];
  size += s.size;
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
  memset(chars, 0, sizeof(chars));
}

bool MyString1::empty()
{
  return size == 0;
}

int MyString1::find(char ch)
{
  for(int i = 0; i < size; i++)
    if(chars[i] == ch)
      return i;
  return -1; // Return -1 if character not found
}
