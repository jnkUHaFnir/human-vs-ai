MyString1::MyString1(char chars[], int size)
{
  // Copy the contents of chars[] to this->chars[] using strcpy
  strcpy(this->chars, chars);

  this->size = size;
}
MyString1 MyString1::append(MyString1 s)
{
  for(int i = size; i < size + s.length(); i++)
    chars[i] = s.at(i - size);
}
void MyString1::clear()
{
  size = 0;
  memset(chars, '\0', sizeof(chars));
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
  for(int i = 0; i < size; i++)
    if(chars[i] == ch)
      return i;
}
