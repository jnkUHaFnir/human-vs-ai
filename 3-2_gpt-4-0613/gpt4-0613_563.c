myString1.cpp

```C
#include "myString1.h"
#include <cstring> // for strlen
using namespace std;

MyString1::MyString1(const char* chars, int size)
{
  this->size = size;
  this->chars = new char[size]; // Allocate memory
  strncpy(this->chars, chars, size); // Copy string
}

MyString1::~MyString1()
{
  delete [] this->chars; // Free memory
}

MyString1 MyString1::append(const MyString1 &s)
{
  // You need to allocate new memory, copy old string, append new string and free old memory...
 }

char MyString1::at(int index) const
{
  return chars[index];
}

int MyString1::length() const
{
  return size;
}

void MyString1::clear()
{
  delete [] this->chars; // Free old memory
  chars = new char[1]; // Allocate new memory
  chars[0] = '\0'; // Empty string
  size = 0;
}

bool MyString1::empty() const
{
  return (size == 0); // If size is 0 then string is empty
}

int MyString1::find(char ch) const
{
  for(int i = 0; i < size; i++)
    if(chars[i] == ch) // Use == for comparison
      return i;
  return -1; // Return -1 if char not found
}

Notice you create `"cat"` with size `4`, but "cat" is size `3`, the fourth character is `'\0'` which is the termination character in C-style strings. 

Append function is not implemented because it needs allocation of new memory, copy old string, append new string and free old memory. It's just the same logic as in constructor when you copy chars input parameter into this->chars.

