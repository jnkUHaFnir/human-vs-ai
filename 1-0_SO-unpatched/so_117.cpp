    MyString1::MyString1(const char* chars)
    {
      this->chars = (char*) malloc(strlen(chars)+1); //this will allocate an array of strlen() chars +1
      strcpy(this->chars,chars);
    }