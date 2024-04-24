LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) { 
    if(valVal != NULL) {            
        // Allocate memory for the string and add the null-terminator
        val = new char[strlen(valVal)+1];
        strcpy(val, valVal);
    }
    else {
        val = NULL; 
    }
}

LField(const LField &clone) { 
    if (val != NULL) {    // Only delete if we have allocated memory
        delete[] val;
    }
    // If clone.val is not NULL, allocate memory and copy the string
    if (clone.val != NULL) {
        val = new char[strlen(clone.val) + 1];
        strcpy(val, clone.val);
    } else {
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
        if (val != NULL) {    // Only delete if we have allocated memory
            delete[] val;
        }
        // If lfieldobj.val is not NULL, allocate memory and copy the string
        if (lfieldobj.val != NULL) {                
            val = new char[strlen(lfieldobj.val) + 1];
            strcpy(val, lfieldobj.val);
        } else {
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

~LField() { 
    // Only delete if we have allocated memory
    if(val != NULL) delete[] val;
}
