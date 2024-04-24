myString1.cpp:6: error: expected primary-expression before ‘]’ token
myString1.cpp:6: error: expected primary-expression before ‘]’ token
myString1.cpp:11: error: invalid use of member (did you forget the ‘&’ ?)
myString1.cpp:25: error: expected primary-expression before ‘]’ token
myString1.cpp:25: error: expected primary-expression before ‘{’ token
myString1.cpp:25: error: expected `;' before ‘{’ token
myString1.cpp:29: error: expected primary-expression before ‘]’ token
myString1.cpp:31: error: expected primary-expression before ‘else’
myString1.cpp:31: error: expected `;'  before ‘else’
myString1.cpp:31:13: error: ‘else’ without a previous ‘if’
MyString1::MyString1(char chars[], int size)
{
    for (int i = 0; i < size; i++) {
        this->chars[i] = chars[i];
    }
    this->size = size;
}

MyString1 MyString1::append(MyString1 &s)
{
    for (int i = size; i < size + s.length(); i++) {
        chars[i] = s.at(i - size);
    }
}

void MyString1::clear()
{
    size = 0;
    for (int i = 0; i < size; i++) {
        chars[i] = '\0';
    }
}

bool MyString1::empty()
{
    if(size == 0) {
        return true;
    } else {
        return false;
    }
}

int MyString1::find(char ch)
{
    for (int i = 0; i < size; i++) {
        if (chars[i] == ch) {
            return i;
        }
    }
    return -1; // Return -1 if character not found
}
