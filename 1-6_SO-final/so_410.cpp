    LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = "", bool canEditVal = true) { 
        if(strlen(valVal) > 0) {            
          //doesn't jump in here since valVal is empty
        }
        else {
          val = new char[1];
          *val = 0;
        }
    }