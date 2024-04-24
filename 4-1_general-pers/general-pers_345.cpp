#include <cstring>

class LField {
private:
    char *val;

public:
    LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = nullptr, bool canEditVal = true) {
        if (valVal != nullptr) {
            val = new char[strlen(valVal) + 1];
            strcpy(val, valVal);
        }
        else {
            val = nullptr;
        }
    }

    LField(const LField &clone) {
        if (clone.val != nullptr) {
            val = new char[strlen(clone.val) + 1];
            strcpy(val, clone.val);
        }
        else {
            val = nullptr;
        }
    }

    LField& operator=(const LField &lfieldobj) {
        if (this != &lfieldobj) {
            delete[] val;
            if (lfieldobj.val != nullptr) {
                val = new char[strlen(lfieldobj.val) + 1];
                strcpy(val, lfieldobj.val);
            }
            else {
                val = nullptr;
            }
        }
        return *this;
    }

    ~LField() {
        delete[] val;
    }
};

int main() {
    LField l(0, 0, 0, "");
    return 0;
}
