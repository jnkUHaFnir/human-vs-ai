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

MyString1::MyString1(char chars[], int size)
{
  this->chars = new char[size];
  strcpy(this->chars, chars);
  this->size = size;
}

MyString1 MyString1::append(MyString1 s)
{
   int newSize = size + s.length();
   char* newChars = new char[newSize];
   strcpy(newChars, chars);
   strcat(newChars, s.chars);

   MyString1 result(newChars, newSize);
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
  return -1;
}
#include <iostream>
#include "myString1.h"
using namespace std;

int main()
{
  MyString1 first("cat", 3);
  MyString1 second("dog", 3);
  cout << first.at(0) << " and " << second.at(0) << endl;
  MyString1 concatenated = first.append(second);
  cout << concatenated.at(6) << endl;

  return 0;
}
