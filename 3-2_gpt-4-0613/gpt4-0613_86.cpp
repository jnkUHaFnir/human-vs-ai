#ifndef MYSTRING1_H
#define MYSTRING1_H
class MyString1
{
  private:
   std::string chars; //You should use std::string instead of char[] in this case
   int size;
  public:
   MyString1();
   MyString1(std::string chars, int size);
   MyString1 append(MyString1 s);
   char at(int index);
   int length();
   void clear();
   bool empty();
   int find(char ch);
};
#endif
#include "myString1.h"
using namespace std;
MyString1::MyString1(std::string chars, int size)
{
  this->chars = chars;
  this->size = size;
}
MyString1 MyString1::append(MyString1 s)
{
  this->chars += s.chars; //concatenate two strings
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
  chars.clear(); //std::string has clear() function
}
bool MyString1::empty()
{
  return chars.empty(); //std::string also has empty() function
}
int MyString1::find(char ch)
{
  for(int i = 0; i < size; i++)
    if(chars[i] == ch) //it should be '==' not '='
      return i;
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
