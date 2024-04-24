    char MyString1::at(int index)
    {
      //if it's out of bounds let's return -1 which will signify that we got an out of bounds value  (could also throw an exception here but that's a different subject altogether)
      if(index > strlen(this->chars) || index <0)
          return -1;
    
      return chars[index];
    }
 