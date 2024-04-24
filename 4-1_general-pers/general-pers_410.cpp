LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) { 
    if(valVal != NULL) {
        val = new char[strlen(valVal) + 1]; // allocate memory
        strcpy(val, valVal);
    } else {
        val = NULL; // set to NULL
    }
}

LField(const LField &clone) { 
    if (clone.val) {
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
        if (val) {
            delete[] val; // deallocate existing memory
        }
        if (lfieldobj.val) {
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
    if (val) {
        delete[] val; // clean up allocated memory
    }
}
