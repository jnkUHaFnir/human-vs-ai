    void MyString1::~MyString1()
    {
      free(this->chars);
    }