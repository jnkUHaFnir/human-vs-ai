MyString1::MyString1(char* chars, int length)
{
  this->chars = new char[length + 1]; // allocate memory for the chars array
  for (int i = 0; i < length; i++) {
    this->chars[i] = chars[i];
  }
  this->chars[length] = '\0'; // null-terminate the string
  this->size = length;
}
MyString1 MyString1::append(MyString1 s)
{
  for(int i=0; i<s.size; i++) {
    if(size + i < MAX_SIZE) {
      chars[size + i] = s.chars[i];
    }
  }
  size += s.size;
  return *this;
}
void MyString1::clear()
{
  delete[] chars;
  chars = new char[1];
  chars[0] = '\0';
  size = 0;
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
  for(int i = 0; i < size; i++) {
    if(chars[i] == ch) {
      return i;
    }
  }
  return -1; // return -1 if character not found
}
