LField(const LField &clone) {
  // No need to delete[] val here; it's not initialized yet!
  if (clone.val != NULL) {
    val = new char[strlen(clone.val) + 1]; 
    strcpy(val, clone.val);
  } else {
    val = NULL;
  }
  // Copy other fields
  rowNum = clone.rowNum;
  colNum = clone.colNum;
  width = clone.width;
  canEdit = clone.canEdit;
  index = clone.index;
}
LField& operator=(const LField &lfieldobj) {
  if (this != &lfieldobj) {
    if (val) {
      delete[] val;
      val = NULL; // Avoid dangling pointer after deletion
    }

    if (lfieldobj.val != NULL) {
      val = new char[strlen(lfieldobj.val) + 1];
      strcpy(val, lfieldobj.val);
    }
    
    // Copy other fields
    rowNum = lfieldobj.rowNum;
    colNum = lfieldobj.colNum;
    width = lfieldobj.width;
    canEdit = lfieldobj.canEdit;
    index = lfieldobj.index;
  }

  return *this;
}
~LField() { 
  if (val) { // Only delete if val is non-NULL
    delete[] val;
  }
}
LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) { 
  if (valVal != NULL && strlen(valVal) > 0) {
    val = new char[strlen(valVal) + 1]; // +1 for null terminator
    strcpy(val, valVal);
  } else {
    val = NULL; // Explicitly setting it to NULL
  }
  // Initialize other fields...
}
