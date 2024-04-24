#ifndef MYSTRING1_H
#define MYSTRING1_H

#include <vector>

class MyString1
{
  private:
   std::vector<char> chars;
  public:
   MyString1(char chars[], int size);
   // Other methods...
};
#endif

// Constructor example:
MyString1::MyString1(char chars[], int size) : chars(chars, chars + size)
{
}
