#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
  private:
   char *chars; // Use pointer for character array
   int size;
  public:
   MyString1();
   MyString1(const char chars[], int size); // Correct syntax for taking char array
   MyString1 append(MyString1 s);
   char at(int index);
   int length();
   void clear();
   bool empty();
   int find(char ch);
};
#endif
#include "myString1.h"
#include <cstring> // Include header for string functions

using namespace std;

MyString1::MyString1(const char chars[], int size) // Changed to correct syntax
{
  this->chars = new char[size + 1]; // Allocate memory for characters (+1 for null terminator)
  strncpy(this->chars, chars, size); // Copy characters to the member variable
  this->chars[size] = '\0'; // Add the null terminator
  this->size = size;
}

MyString1 MyString1::append(MyString1 s)
{
  int newSize = this->size + s.size;
  char *newChars = new char[newSize + 1];
  
  strncpy(newChars, this->chars, this->size); // Copy current characters
  strncpy(newChars + this->size, s.chars, s.size); // Copy second string characters
  
  newChars[newSize] = '\0'; // Add the null terminator
  
  MyString1 result(newChars, newSize);
  
  delete[] newChars; // Free the dynamically allocated memory
  
  return result;
}

char MyString1::at(int index)
{
  if (index >= 0 && index < size)
    return chars[index];
  else
    return '\0'; // Return null character for out of bounds access
}

int MyString1::length()
{
  return size;
}

void MyString1::clear()
{
  delete[] chars; // Free the memory
  chars = new char[1]; // Allocate new memory for an empty string
  chars[0] = '\0'; // Add null terminator
  size = 0;
}

bool MyString1::empty()
{
  return size == 0;
}

int MyString1::find(char ch)
{
  for (int i = 0; i < size; i++)
  {
    if (chars[i] == ch)
      return i;
  }
  
  return -1; // Return -1 if character not found
}
#include <iostream>
#include "myString1.h"

using namespace std;

int main()
{
  MyString1 first("cat", 3); // Pass the actual length of the string excluding the null terminator
  MyString1 second("dog", 3);
  cout << first.at(1) << " and " << second.at(1) << endl;

  MyString1 combined = first.append(second);
  cout << combined.at(6) << endl;

  return 0;
}
