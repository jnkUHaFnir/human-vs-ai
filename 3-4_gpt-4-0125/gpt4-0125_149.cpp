void Expression::add_meaning(char * p2c) {
    // Expand meanings array by one
    char** temp_meanings = new char*[meanings_ctr + 1];
    for (int i = 0; i < meanings_ctr; ++i) {
        temp_meanings[i] = meanings[i];
    }
    delete[] meanings; // Delete the old array
    meanings = temp_meanings;
    
    // Allocate memory for the new meaning and copy it
    meanings[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(meanings[meanings_ctr], p2c);
    
    ++meanings_ctr; // Increase the count of meanings
}
Expression::~Expression() {
    for(int i = 0; i < meanings_ctr; i++) {
        delete[] meanings[i];
    }
    delete[] meanings; // Delete array of pointers
    delete[] word_with_several_meanings; // Delete char array
}
