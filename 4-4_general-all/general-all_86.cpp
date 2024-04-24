#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
  private:
   char* chars;
   int size;
  public:
   MyString1();
   MyString1(const char* chars, int size);
   MyString1 append(MyString1 s);
   char at(int index);
   int length();
   void clear();
   bool empty();
   int find(char ch);
};
#endif
#include "myString1.h"
#include <cstring>

MyString1::MyString1(const char* chars, int size)
{
  this->chars = new char[size];
  strncpy(this->chars, chars, size);
  this->size = size;
}

MyString1 MyString1::append(MyString1 s)
{
  char* newChars = new char[this->size + s.size];
  strncpy(newChars, this->chars, this->size);
  strncpy(&newChars[this->size], s.chars, s.size);
  
  MyString1 result(newChars, this->size + s.size);
  delete[] newChars;
  return result;
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
    if(chars[i] == ch)
      return i;
  return -1; // Return -1 if not found
}
#include <iostream>
#include "myString1.h"
using namespace std;

int main()
{
  MyString1 first("cat", 3);
  MyString1 second("dog", 3);
  cout << first.at(0) << " and " << second.at(0) << endl;
  MyString1 combined = first.append(second);
  cout << combined.at(6) << endl;

  return 0;
}
