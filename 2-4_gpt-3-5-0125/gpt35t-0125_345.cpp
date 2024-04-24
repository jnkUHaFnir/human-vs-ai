~LField() { 
    if (val != NULL) {
        delete[] val;
        val = NULL;
    }
}
