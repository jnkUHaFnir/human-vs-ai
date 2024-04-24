#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1 {
  private:
    char* chars; // Use a pointer to a dynamically allocated array
    int size;
  public:
    MyString1(); // Default constructor
    MyString1(const char* chars, int size); // Pass a const char* to avoid modifying the input string
    MyString1(const MyString1& other); // Copy constructor
    ~MyString1(); // Destructor to deallocate memory
    MyString1 append(const MyString1& s);
    char at(int index) const; // 'const' makes it clear that this method doesn't modify the object
    int length() const;
    void clear();
    bool empty() const;
    int find(char ch) const;
};
#endif
#include <cstring> // For strcpy, strcat
#include "myString1.h"
using namespace std;

// Include the necessary constructor, destructor and methods implementations, considering the provided headers as reference
// ...

int main() {
    // ...
    return 0;
}
