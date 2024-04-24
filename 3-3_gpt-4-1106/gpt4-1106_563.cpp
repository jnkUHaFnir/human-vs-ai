// myString1.h
#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1
{
  private:
    char *chars; // Change from char chars[] to char *chars
    int size;
  public:
    MyString1();
    MyString1(const char *chars, int size); // Add const for passing literal strings
    MyString1 append(const MyString1 &s); // Change to const reference
    char at(int index) const; // Add const to make it usable on const objects
    int length() const; // Add const for the same reason
    void clear();
    bool empty() const; // Add const again
    int find(char ch) const; // Add const as well
};
#endif
// myString1.cpp
#include "myString1.h"
#include <cstring> // Needed for strcpy and strcat

// Default constructor (allocating some default space)
MyString1::MyString1() : chars(new char[1]), size(0) {
    chars[0] = '\0';
}

// Parameterized constructor (allocate space and copy the contents)
MyString1::MyString1(const char *str, int size) : size(size) {
    chars = new char[size + 1];
    std::strcpy(chars, str);
}

// Destructor (release dynamically-allocated memory)
MyString1::~MyString1() {
    delete[] chars;
}

// Return value should probably be a reference to the modified object.
// Also, the append logic should concatenate strings, not just add elements at the end.
MyString1& MyString1::append(const MyString1 &s) {
    int newSize = size + s.size;
    char *newChars = new char[newSize + 1];
    std::strcpy(newChars, chars);
    std::strcat(newChars, s.chars);
    
    delete[] chars;
    chars = newChars;
    size = newSize;

    return *this;
}

// Return a character at a given index
char MyString1::at(int index) const {
    if(index >= 0 && index < size) {
        return chars[index];
    }
    // Return some error character, typically '\0' is used for strings.
    return '\0';
}

// Return the length of the string
int MyString1::length() const {
    return size;
}

// Clear the string by setting its size to 0 and the first character to null terminator
void MyString1::clear() {
    size = 0;
    chars[0] = '\0';
}

// Check if the string is empty
bool MyString1::empty() const {
    return size == 0;
}

// Find the first occurrence of a character
int MyString1::find(char ch) const {
    for(int i = 0; i < size; i++) {
        // Corrected to use comparison operator '=='
        if(chars[i] == ch) {
            return i;
        }
    }
    return -1; // Typically, if character isn't found, -1 is returned.
}
// testMyString1.cpp
#include <iostream>
#include "myString1.h"

using namespace std;

int main() {
    MyString1 first("cat", 3); // Correct size
    MyString1 second("dog", 3); // Correct size

    cout << first.at(1) << " and " << second.at(1) << endl;
    first.append(second);

    // Assuming you modify the append to return *this, we would call like this:
    cout << first.at(first.length() - 1) << endl; // Print last character

    return 0;
}
