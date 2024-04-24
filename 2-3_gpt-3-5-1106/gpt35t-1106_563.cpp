#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
  private:
   char chars[100];
   size_t size;
  public:
   MyString1();
   MyString1(char chars[], size_t size);
   MyString1 append(MyString1 s);
   char at(int index);
   size_t length();
   void clear();
   bool empty();
   size_t find(char ch);
};
#endif
#include "myString1.h"
#include <cstring>
#include <iostream>
using namespace std;

MyString1::MyString1(char chars[], size_t size)
{
  strncpy(this->chars, chars, size);
  this->size = size;
}

MyString1 MyString1::append(MyString1 s)
{
  size_t originalSize = size;
  for(size_t i = 0; i < s.size; i++)
    chars[size + i] = s.chars[i];
  size += s.size;
  return *this;
}

char MyString1::at(int index)
{
  return chars[index];
}

size_t MyString1::length()
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

size_t MyString1::find(char ch)
{
  for(size_t i = 0; i < size; i++)
    if(chars[i] == ch)
      return i;
  return -1; // Or any value to indicate not found
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
  cout << first.at(6) << endl;

  return 0;
}
