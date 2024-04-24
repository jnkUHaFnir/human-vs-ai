#include <string>

class MyString1
{
   std::string chars; // Switch to std::string for simplicity
   // ...
};
MyString1::MyString1(char chars[], int size)
{
  this->chars = chars; // std::string can be directly assigned.
  this->size = size;
}
MyString1 MyString1::append(MyString1 s)
{
  this->chars += s.chars; // Using std::string's += operator
  this->size = chars.size(); // updating size
  return *this;
}
bool MyString1::empty()
{
  return chars.empty(); // With std::string, simply return this
}
void MyString1::clear()
{
  chars.clear(); // Clears the string
  size = 0;
}
int MyString1::find(char ch)
{
  for(int i = 0; i < size; i++)
    if(chars[i] == ch) // Use == for comparison
      return i;
  return -1; // If not found
}
