LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) { 
    if(valVal != NULL) {            
        // Handle non-empty input
    }
    else {
        val = NULL; // Assign NULL to the pointer
    }
}
LField(const LField &clone) { 
  if (clone.val != NULL) {
     val = new char[strlen(clone.val) + 1]; 
     strcpy(val, clone.val);
  }
  else {
    val = NULL;
  }
  rowNum = clone.rowNum;
  colNum = clone.colNum;
  width = clone.width;
  canEdit = clone.canEdit;
  index = clone.index;
}

LField& operator=(const LField &lfieldobj) {
    if (this != &lfieldobj) {
        if (lfieldobj.val != NULL) {                
            val = new char[strlen(lfieldobj.val) + 1];
            strcpy(val, lfieldobj.val);
        }
        else {
            val = NULL;
        }
        rowNum = lfieldobj.rowNum;
        colNum = lfieldobj.colNum;
        width = lfieldobj.width;
        canEdit = lfieldobj.canEdit;
        index = lfieldobj.index;
    }

    return *this;
}
