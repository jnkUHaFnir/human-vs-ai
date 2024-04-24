// myString1.h
#ifndef MYSTRING1_H
#define MYSTRING1_H

#include <string>

class MyString1
{
  private:
   std::string str;
  public:
   MyString1(const std::string& s = "") : str(s) {}
   MyString1 append(const MyString1& s);
   char at(int index) const;
   int length() const;
   void clear();
   bool empty() const;
   int find(char ch) const;
};

#endif

// myString1.cpp
#include "myString1.h"

MyString1 MyString1::append(const MyString1& s)
{
  str += s.str;
  return *this;
}

char MyString1::at(int index) const
{
  return str.at(index);
}

int MyString1::length() const
{
  return str.length();
}

void MyString1::clear()
{
  str.clear();
}

bool MyString1::empty() const
{
  return str.empty();
}

int MyString1::find(char ch) const
{
  auto pos = str.find(ch);
  return pos != std::string::npos ? pos : -1;
}

// testMyString1.cpp
#include <iostream>
#include "myString1.h"

int main()
{
  MyString1 first("cat");
  MyString1 second("dog");
  std::cout << first.at(1) << " and " << second.at(1) << std::endl;
  first.append(second);
  std::cout << first.at(4) << std::endl;

  return 0;
}
