    int str2int (const string &str) {
      stringstream ss(str);
      int num;
      ss >> num;
      return num;
    }