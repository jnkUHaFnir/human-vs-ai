#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
  private:
   char* chars; // Update to use pointer
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
#include <cstring> // Include for strlen

using namespace std;

MyString1::MyString1(char chars[], int size)
{
  this->chars = new char[size + 1]; // Allocate memory and copy chars
  strncpy(this->chars, chars, size);
  this->chars[size] = '\0'; // Null-terminate the string
  this->size = size;
}

MyString1 MyString1::append(MyString1 s)
{
  char* newChars = new char[size + s.length() + 1]; // Allocate memory for the new string
  strcpy(newChars, chars); // Copy current string
  strcat(newChars, s.chars); // Concatenate the new string
  MyString1 result(newChars, size + s.length()); // Create a new MyString1 object
  delete[] newChars; // Free the memory
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
  delete[] chars; // Free memory before resetting pointer
  chars = new char[1]; // Allocate new memory and null-terminate
  chars[0] = '\0';
  size = 0;
}

bool MyString1::empty()
{
  return size == 0;
}

int MyString1::find(char ch)
{
  for(int i = 0; i < size; i++)
    if(chars[i] == ch) // Replace assignment operator with equality check
      return i;
  
  return -1; // Return -1 if not found
}
