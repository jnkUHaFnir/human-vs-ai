    MyString1::MyString1(char* chars)
    {
      this->chars = malloc(strlen(chars)+1); //this will allocate an array of strlen() chars +1
      strcpy(this->chars,chars);
    }