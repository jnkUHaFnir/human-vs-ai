LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) { 
    if (valVal != NULL) {  
        val = new char[strlen(valVal) + 1]; // +1 for null terminator
        strcpy(val, valVal);
    }
    else {
        val = NULL; 
    }
}

LField(const LField &clone) { 
    val = NULL; // Ensure val is initialized
    if (clone.val != NULL) {
        val = new char[strlen(clone.val) + 1]; // +1 for null terminator
        strcpy(val, clone.val);
    }
    rowNum = clone.rowNum;
    colNum = clone.colNum;
    width = clone.width;
    canEdit = clone.canEdit;
    index = clone.index;
}

LField& operator=(const LField &lfieldobj) {
    if (this != &lfieldobj) {
        delete[] val; // Make sure to free existing memory

        val = NULL;
        if (lfieldobj.val != NULL) {                
            val = new char[strlen(lfieldobj.val) + 1];
            strcpy(val, lfieldobj.val);
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
    delete[] val; // Make sure to delete allocated memory
}
