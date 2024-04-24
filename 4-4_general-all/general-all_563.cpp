#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
  private:
   char* chars;
   int size;
  public:
   MyString1();
   MyString1(char* chars, int size);
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
using namespace std;

MyString1::MyString1(char* chars, int size)
{
  this->size = size;
  this->chars = new char[size];
  strcpy(this->chars, chars);
}

MyString1 MyString1::append(MyString1 s)
{
  int newLength = size + s.length();
  char* newChars = new char[newLength];
  
  strcpy(newChars, chars);
  for(int i = 0; i < s.length(); i++) {
    newChars[size + i] = s.at(i);
  }

  MyString1 result(newChars, newLength);
  delete[] newChars;
  return result;
}
