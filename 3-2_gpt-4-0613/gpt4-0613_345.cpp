val = new char[strlen(lfieldobj.val) + 1]; 
LField(const LField &clone) { 

  if (val)
    delete[] val;

  if (clone.val != NULL) {
     val = new char[strlen(clone.val) + 1]; //include room for null terminator
     strcpy(val, clone.val);
  }
  else 
    val = NULL;

  rowNum = clone.rowNum;
  colNum = clone.colNum;
  width = clone.width;
  canEdit = clone.canEdit;
  index = clone.index;
}

LField& operator=(const LField &lfieldobj) {
    
  if (this != &lfieldobj) {

    if (val)
      delete[] val;

    if (lfieldobj.val != NULL) {
      val = new char[strlen(lfieldobj.val) + 1]; //include room for null terminator
      strcpy(val, lfieldobj.val);
    }
    else 
      val = NULL;

    rowNum = lfieldobj.rowNum;
    colNum = lfieldobj.colNum;
    width = lfieldobj.width;
    canEdit = lfieldobj.canEdit;
    index = lfieldobj.index;
  }

  return *this;
}
LField() : val(NULL) {}
