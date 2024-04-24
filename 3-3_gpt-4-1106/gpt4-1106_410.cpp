class LField {
private:
    char* val; // Make sure you have some member variable to hold the pointer
    // Other members...

public:
    LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) {
        if (valVal != NULL) {
            val = new char[strlen(valVal) + 1]; // +1 for null-terminator
            strcpy(val, valVal);
        } else {
            val = NULL;
        }
        // Initialize other members...
    }

    LField(const LField &clone) {
        if (clone.val != NULL) {
            val = new char[strlen(clone.val) + 1];
            strcpy(val, clone.val);
        } else {
            val = NULL;
        }
        // Copy other members...
    }

    LField& operator=(const LField &lfieldobj) {
        if (this != &lfieldobj) {
            delete[] val; // Delete old val
            if (lfieldobj.val != NULL) {
                val = new char[strlen(lfieldobj.val) + 1];
                strcpy(val, lfieldobj.val);
            } else {
                val = NULL;
            }
            // Assign/copy other members...
        }

        return *this;
    }

    ~LField() {
        delete[] val; // It's safe to delete a NULL pointer, no need for if(val)
    }

    // Rest of the class...
};
