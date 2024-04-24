~LField() {
  delete val;
}
LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) { 
  if(valVal != NULL) {       
    // do something with non-empty value
  }
  else {
    val = NULL; // set to NULL for empty value
  }
}
