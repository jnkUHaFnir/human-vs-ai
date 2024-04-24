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
  this->size = size;
  this->chars = new char[size + 1]; // Allocate memory for chars
  strncpy(this->chars, chars, size);
  this->chars[size] = '\0'; // Null-terminate the string
}

MyString1 MyString1::append(MyString1 s)
{
  int newSize = size + s.length();
  char* temp = new char[newSize + 1];
  strncpy(temp, chars, size);
  strncpy(temp + size, s.chars, s.size);
  temp[newSize] = '\0';
  MyString1 result(temp, newSize);
  delete[] temp;
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
  delete[] chars; // Release memory
  size = 0;
  chars = new char[size + 1];
  chars[0] = '\0'; // Null-terminate the string
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
  return -1; // Return -1 if not found.
}
#include <iostream>
#include "myString1.h"
using namespace std;

int main()
{
  MyString1 first("cat", 3);
  MyString1 second("dog", 3);
  cout << first.at(1) << " and " << second.at(1) << endl;
  MyString1 combined = first.append(second);
  cout << combined.at(6) << endl;

  return 0;
}
