LField(int rowNumVal, int colNumVal, int widthVal, const char* valVal = nullptr, bool canEditVal = true) { 
    if(valVal == nullptr || valVal[0] == '\0') {            
        val = nullptr; // set val to NULL
    } 
    // your other initialization code here
}

~LField() { 
    delete[] val; // make sure val is not NULL before attempting to delete it
}
LField(const LField &clone) { 
    if (clone.val != nullptr) {
        val = new char[strlen(clone.val) + 1]; 
        strcpy(val, clone.val);
    } else {
        val = nullptr;
    }
    // your other initialization code here
}

LField& operator=(const LField &lfieldobj) {
    if (this != &lfieldobj) {
        delete[] val; // delete the existing memory before allocating new memory

        if (lfieldobj.val != nullptr) {                
            val = new char[strlen(lfieldobj.val) + 1];
            strcpy(val, lfieldobj.val);
        } else {
            val = nullptr;
        }
        // your assignment code here
    }

    return *this;
}
