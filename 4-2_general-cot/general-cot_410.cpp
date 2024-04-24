#include <iostream>
#include <cstring>

class LField {
private:
    char *val;
    int rowNum;
    int colNum;
    int width;
    bool canEdit;
    int index;

public:
    // Constructor
    LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = nullptr, bool canEditVal = true) : rowNum(rowNumVal),
                                                                                                              colNum(colNumVal),
                                                                                                              width(widthVal),
                                                                                                              canEdit(canEditVal),
                                                                                                              index(0) {
        if (valVal != nullptr && strlen(valVal) > 0) {
            val = new char[strlen(valVal) + 1]; // +1 for null terminator
            strcpy(val, valVal);
        } else {
            val = nullptr;
        }
    }

    // Copy Constructor
    LField(const LField &clone) : rowNum(clone.rowNum),
                                  colNum(clone.colNum),
                                  width(clone.width),
                                  canEdit(clone.canEdit),
                                  index(clone.index) {
        if (clone.val != nullptr) {
            val = new char[strlen(clone.val) + 1]; // +1 for null terminator
            strcpy(val, clone.val);
        } else {
            val = nullptr;
        }
    }

    // Assignment Operator
    LField& operator=(const LField &lfieldobj) {
        if (this != &lfieldobj) {
            delete[] val;
            if (lfieldobj.val != nullptr) {
                val = new char[strlen(lfieldobj.val) + 1]; // +1 for null terminator
                strcpy(val, lfieldobj.val);
            } else {
                val = nullptr;
            }
            rowNum = lfieldobj.rowNum;
            colNum = lfieldobj.colNum;
            width = lfieldobj.width;
            canEdit = lfieldobj.canEdit;
            index = lfieldobj.index;
        }

        return *this;
    }

    // Destructor
    ~LField() {
        delete[] val;
    }
};

// Sample usage
int main() {
    LField field1(1, 1, 10); // Passing empty string as val
    LField field2(2, 2, 20, "Hello"); // Passing non-empty string as val

    return 0;
}
