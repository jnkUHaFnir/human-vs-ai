~LField() { 
    if (val) {
        delete[] val;
    }
}

LField& operator=(const LField &lfieldobj) {
    if (this != &lfieldobj) {
        // Delete existing val only if it was allocated
        if (val) {
            delete[] val;
        }
        
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
