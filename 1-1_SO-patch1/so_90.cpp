    int str2int (const string &str) {
      stringstream ss(str);
      int num;
      if((ss >> num).fail())
      { 
          //ERROR 
      }
      return num;
    }