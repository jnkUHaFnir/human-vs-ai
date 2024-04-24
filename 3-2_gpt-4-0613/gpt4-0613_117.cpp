#ifndef MYSTRING1_H
#define MYSTRING1_H

#include <vector>

class MyString1
{
  private:
   std::vector<char> chars;
  public:
   MyString1();
   MyString1(const std::vector<char>& chars);
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

MyString1::MyString1(const std::vector<char>& chars)
{
  this->chars = chars;
}

MyString1 MyString1::append(const MyString1& s)
{
  for(int i = char.size(); i< s.length(); i++)
  {
   this->chars.push_back(s.at(i));
  }

  return *this;
}

char MyString1::at(int index)
{
  return chars.at(index);
}

int MyString1::length()
{
  return chars.size();
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
  for(int i = 0; i < chars.size(); i++)
    if(chars[i] == ch)
      return i;

  return -1; // Return -1 if not found.
}
#include <iostream>
#include <vector>
#include "myString1.h"
using namespace std;

int main()
{
  MyString1 first(vector<char>{'c','a','t'});
  MyString1 second(vector<char>{'d','o','g'});
  cout << first.at(1) << " and " << second.at(1) << endl;
  first.append(second);
  cout << first.at(6) << endl;
  return 0;
}
