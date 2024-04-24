LField(int rowNumVal, int colNumVal, int widthVal, const char* valVal = nullptr, bool canEditVal = true) { 
    if (valVal != nullptr) { // Check for nullptr instead of checking for string length
        val = new char[strlen(valVal) + 1]; // +1 for null terminator
        strcpy(val, valVal);
    }
    else {
        val = nullptr; // Initialize to nullptr
    }
}
~LField() { 
    delete[] val; // Ensure val is not null before deleting it
}
