LField(int rowNumVal, int colNumVal, int widthVal, const char *valVal = nullptr, bool canEditVal = true) { 
    if(valVal) {
        val = new char[strlen(valVal) + 1]; // +1 for null terminator
        strcpy(val, valVal);
    } else {
        val = nullptr;
    }
}
