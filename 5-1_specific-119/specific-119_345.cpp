#include <cstring> // for strlen, strcpy
#include <cstdlib> // for NULL

class LField {
private:
    char *val;

public:
    LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) { 
        if(valVal != NULL) {
            val = new char[strlen(valVal) + 1];
            strcpy(val, valVal);
        } else {
            val = NULL; 
        }
    }

    LField(const LField &clone) { 
        if (clone.val != NULL) {
            val = new char[strlen(clone.val) + 1]; 
            strcpy(val, clone.val);
        } else {
            val = NULL;
        }
        // Copy other member variables here
    }

    LField& operator=(const LField &lfieldobj) {
        if (this != &lfieldobj) {
            if (lfieldobj.val != NULL) {                
                val = new char[strlen(lfieldobj.val) + 1];
                strcpy(val, lfieldobj.val);
            } else {
                val = NULL;
            }
            // Copy other member variables here
        }

        return *this;
    }

    ~LField() {
        delete[] val;
    }
};
