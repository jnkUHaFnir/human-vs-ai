LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) {
    rowNum = rowNumVal;
    colNum = colNumVal;
    width = widthVal;
    canEdit = canEditVal;
    index = -1;

    if (valVal != NULL) {
        val = new char[strlen(valVal) + 1];
        strcpy(val, valVal);
    }
    else {
        val = NULL;
    }
}
LField(const LField &clone) {
    rowNum = clone.rowNum;
    colNum = clone.colNum;
    width = clone.width;
    canEdit = clone.canEdit;
    index = clone.index;

    if (clone.val != NULL) {
        val = new char[strlen(clone.val) + 1];
        strcpy(val, clone.val);
    }
    else {
        val = NULL;
    }
}
LField& operator=(const LField &lfieldobj) {
    if (this != &lfieldobj) {
        rowNum = lfieldobj.rowNum;
        colNum = lfieldobj.colNum;
        width = lfieldobj.width;
        canEdit = lfieldobj.canEdit;
        index = lfieldobj.index;

        delete[] val;
        
        if (lfieldobj.val) {
            val = new char[strlen(lfieldobj.val) + 1];
            strcpy(val, lfieldobj.val);
        }
        else {
            val = NULL;
        }
    }

    return *this;
}
