LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = NULL, bool canEditVal = true) { 
    if (valVal != NULL && strlen(valVal) > 0) {            
        // Copy the value of valVal into val if it is not empty
        val = new char[strlen(valVal) + 1]; 
        strcpy(val, valVal);
    }
    else {
        // Set val to NULL if it is empty
        val = NULL; 
    }
}

~LField() { 
    // Only delete[] val if it was previously allocated with new[]
    if (val != NULL) {
        delete[] val;
    }
}
