/*myString1.cpp:
- The assignment of chars[] to {} doesn't work - instead, you should loop through the length of the array and set each element to 0.
- In the empty() function, the condition should check if size is 0, not if the chars[] array itself exists.
- In the find() function, the comparison should use == instead of =.*/

#include "myString1.h"
using namespace std;

MyString1::MyString1(char chars[], int size)
{
  this->chars = new char[size]; // allocate array dynamically
  for(int i = 0; i < size; i++) {
    this->chars[i] = chars[i];
  }
  this->size = size;
}

MyString1 MyString1::append(MyString1 s)
{
  for(int i = size; i < size + s.length(); i++) // use s.length() function
    chars[i] = s.at(i - size); // iterate through s starting at 0
  size += s.length();
  return *this;
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
  for(int i = 0; i < size; i++) {
    chars[i] = 0;
  }
}

bool MyString1::empty()
{
  if(size == 0){ // check if size is 0
    return true;
  }
  else {
    return false;
  }
}

int MyString1::find(char ch)
{
  for(int i = 0; i < size; i++) {
    if(chars[i] == ch){ // use == for comparison
      return i;
    }
  }
  return -1; // return -1 if char is not found
}


/*testMyString1.cpp:
- In the MyString1 constructor calls, the sizes of the strings are incorrect - "cat" and "dog" are both length 3, not 4.*/

#include <iostream>
#include "myString1.h"
using namespace std;

int main()
{
  MyString1 first("cat", 3); // specify correct size
  MyString1 second("dog", 3); // specify correct size
  cout << first.at(1) << " and " << second.at(1) << endl;
  first.append(second);
  cout << first.at(6) << endl;

  return 0;
}