#include <cstring> // for strlen, strcpy

class LField {
private:
    char* val;
    // Other member variables...

public:
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
        if (clone.val != NULL) {
            val = new char[strlen(clone.val) + 1]; 
            strcpy(val, clone.val);
        }
        else {
            val = NULL;
        }
        // Copy other member variables...
    }

    LField& operator=(const LField &lfieldobj) {
        if (this != &lfieldobj) {
            delete[] val; // Delete existing memory

            if (lfieldobj.val != NULL) {
                val = new char[strlen(lfieldobj.val) + 1];
                strcpy(val, lfieldobj.val);
            }
            else {
                val = NULL;
            }
            // Copy other member variables...
        }
        return *this;
    }

    ~LField() { 
        delete[] val; // Make sure val is not NULL before deleting
    }
};
