class LField {
private:
    char *val;
    // other member variables

public:
    LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) { 
        if(valVal != NULL) {
            val = new char[strlen(valVal) + 1];
            strcpy(val, valVal);
        }
        else {
            val = NULL;
        }
        // initialize other member variables
    }

    LField(const LField &clone) { 
        if (clone.val != NULL) {
            val = new char[strlen(clone.val) + 1]; 
            strcpy(val, clone.val);
        }
        else {
            val = NULL;
        }
        // copy other member variables
    }

    LField& operator=(const LField &lfieldobj) {
        if (this != &lfieldobj) {
            // delete existing memory if any
            delete[] val;

            if (lfieldobj.val != NULL) {                
                val = new char[strlen(lfieldobj.val) + 1];
                strcpy(val, lfieldobj.val);
            }
            else {
                val = NULL;
            }

            // copy other member variables
        }

        return *this;
    }

    ~LField() { 
        delete[] val;
    }
};
