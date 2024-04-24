LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) { 
    if(valVal != NULL) {
        val = new char[strlen(valVal) + 1];
        strcpy(val, valVal);
    }
    else {
        val = NULL;
    }
}
~LField() { 
    if (val) {
        delete[] val;
    }
}
