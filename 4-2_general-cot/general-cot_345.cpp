#include <cstring> // for strlen, strcpy
#include <iostream>

class LField {
private:
    char *val;
    int rowNum;
    int colNum;
    int width;
    bool canEdit;
    int index;

public:
    LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) 
        : rowNum(rowNumVal), colNum(colNumVal), width(widthVal), canEdit(canEditVal), index(0) {
        
        if (valVal != NULL) {            
            val = new char[strlen(valVal) + 1];
            strcpy(val, valVal);
        }
        else {
            val = NULL;
        }
    }

    LField(const LField &clone) 
        : rowNum(clone.rowNum), colNum(clone.colNum), width(clone.width), canEdit(clone.canEdit), index(clone.index) {
        
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
            delete[] val;

            if (lfieldobj.val != NULL) {
                val = new char[strlen(lfieldobj.val) + 1];
                strcpy(val, lfieldobj.val);
            }
            else {
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
        delete[] val;
    }
};

int main() {
    LField field1(1, 1, 10, "test");
    LField field2(field1);

    return 0;
}
