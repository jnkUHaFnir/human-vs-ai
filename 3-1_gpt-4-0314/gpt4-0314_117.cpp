#ifndef MYSTRING1_H
#define MYSTRING1_H

class MyString1 {
  private:
    char *chars; // changed to a pointer
    int size;

  public:
    MyString1();
    MyString1(char *chars, int size); // changed to a pointer
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

MyString1::MyString1(char *chars, int size) {
    this->chars = new char[size]; // allocate memory
    for (int i = 0; i < size; i++) {
        this->chars[i] = chars[i];
    }
    this->size = size;
}

MyString1 MyString1::append(MyString1 s) {
    int newSize = size + s.length();
    char *newChars = new char[newSize];
    for (int i = 0; i < size; i++) {
        newChars[i] = this->chars[i];
    }
    for (int i = size; i < newSize; i++) {
        newChars[i] = s.at(i - size);
    }
    delete[] this->chars; // delete old memory
    this->chars = newChars;
    this->size = newSize;
    return *this;
}

char MyString1::at(int index) {
    return chars[index];
}

int MyString1::length() {
    return size;
}

void MyString1::clear() {
    delete[] chars; // delete old memory
    size = 0;
    chars = nullptr;
}

bool MyString1::empty() {
    return size == 0;
}

int MyString1::find(char ch) {
    for (int i = 0; i < size; i++) {
        if (chars[i] == ch)
            return i;
    }
    return -1;
}
#include <iostream>
#include "myString1.h"
using namespace std;

int main() {
    MyString1 first("cat", 3); //size of string "cat" is 3
    MyString1 second("dog", 3); //size of string "dog" is 3
    cout << first.at(1) << " and " << second.at(1) << endl;
    first.append(second);
    cout << first.at(4) << endl;

    return 0;
}
