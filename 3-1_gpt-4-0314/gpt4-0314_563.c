class MyString1
{
  private:
   char* chars; // Change this
   int size;
  // ...
};
MyString1::MyString1(char chars[], int size)
{
  this->chars = new char[size]; // Add this
  for (int i = 0; i < size; i++) { // Add this
    this->chars[i] = chars[i]; // Change
  }
  this->size = size;
}
MyString1 MyString1::append(MyString1 s)
{
  int newSize = size + s.length(); // Add this
  char* newChars = new char[newSize]; // Add this

  for(int i = 0; i < size; i++)
    newChars[i] = chars[i]; // Change this

  for(int i = size; i < newSize; i++)
    newChars[i] = s.at(i - size); // Change this

  delete[] chars; // Add this
  chars = newChars; // Add this
  size = newSize; // Add this
}
void MyString1::clear()
{
  size = 0;
  delete[] chars; // Change this
  chars = nullptr; // Change this
}
bool MyString1::empty()
{
  return size == 0; // Change this
}
int MyString1::find(char ch)
{
  for(int i = 0; i < size; i++)
    if(chars[i] == ch) // Change this
      return i;
  return -1; // Add this
}
class MyString1
{
  // ...
  public:
   MyString1(); // Add this
   MyString1(char chars[], int size);
  // ...
};
MyString1::MyString1() // Add this
{
  chars = nullptr;
  size = 0;
}
