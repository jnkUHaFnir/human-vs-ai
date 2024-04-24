void Expression::add_meaning(char *p2c) {
    // Create a new array one size larger than the current meanings array
    char **new_meanings = new char *[meanings_ctr + 1];

    // Copy the old meanings to the new array
    for (int i = 0; i < meanings_ctr; ++i) {
        int len = strlen(meanings[i]);
        new_meanings[i] = new char[len + 1];
        strcpy(new_meanings[i], meanings[i]);
    }

    // Add the new meaning
    new_meanings[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(new_meanings[meanings_ctr], p2c);

    // Increment the counter after adding the new meaning
    meanings_ctr++;

    // Delete the old meanings and replace with the new array
    for (int i = 0; i < meanings_ctr - 1; ++i) {
        delete[] meanings[i];
    }
    delete[] meanings;

    // Replace the old meanings with the new meanings
    meanings = new_meanings;
}
Expression::~Expression() {
    for(int i = 0; i < meanings_ctr; i++){
        delete[] meanings[i];
    }
    delete[] meanings; // Deleting the memory we allocated for pointers
    delete[] word_with_several_meanings; // Deleting the memory we allocated for the word_with_several_meanings
}
