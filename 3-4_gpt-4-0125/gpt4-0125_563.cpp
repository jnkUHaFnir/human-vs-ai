#ifndef MYSTRING1_H
#define MYSTRING1_H

#include <string>

class MyString1
{
  private:
   std::string chars;
  public:
   MyString1();
   MyString1(const char* chars);
   MyString1 append(const MyString1& s);
   char at(int index);
   int length();
   void clear();
   bool empty();
   int find(char ch);
};

#endif
#include "myString1.h"
using namespace std;

MyString1::MyString1(const char* chars): chars(chars) {}

MyString1 MyString1::append(const MyString1& s)
{
  this->chars += s.chars;
  return *this;
}

char MyString1::at(int index)
{
  return chars.at(index);
}

int MyString1::length()
{
  return chars.length();
}

void MyString1::clear()
{
  chars.clear();
}

bool MyString1::empty()
{
  return chars.empty();
}

int MyString1::find(char ch)
{
  return chars.find(ch);
}
