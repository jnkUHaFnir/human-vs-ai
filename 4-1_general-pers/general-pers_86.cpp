// myString1.h
#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
private:
   char chars[100]; // Fixed size or dynamic memory allocation should be used
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
// myString1.cpp
#include "myString1.h"
#include <iostream>
#include <cstring>

using namespace std;

MyString1::MyString1(char chars[], int size)
{
  this->size = size;
  memcpy(this->chars, chars, size); // Copy characters one by one
  this->chars[size] = '\0'; // Add null character at the end
}

MyString1 MyString1::append(MyString1 s)
{
  for(int i = 0; i < s.length(); i++) {
    chars[size + i] = s.at(i);
  }
  size += s.length();
  chars[size] = '\0'; // Add null character at the end
  return *this; // Return the modified MyString1 object
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
  chars[0] = '\0'; // Set the first character to null character
}

bool MyString1::empty()
{
  if(size == 0){
    return true;
  }
  else {
    return false;
  }
}

int MyString1::find(char ch)
{
  for(int i = 0; i < size; i++) {
    if(chars[i] == ch) {
      return i;
    }
  }
  return -1; // Return -1 if character not found
}
