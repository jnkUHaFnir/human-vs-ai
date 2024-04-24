void Expression::add_meaning(char *p2c) {
    char **temp_meaning = new char*[meanings_ctr + 1]; // Create new array with size +1
    for(int i = 0; i < meanings_ctr; i++) {
        temp_meaning[i] = meanings[i]; // Copy pointers
    }

    // Add new meaning
    temp_meaning[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(temp_meaning[meanings_ctr], p2c);
    meanings_ctr++; // Increase counter after successful addition

    // Delete old meanings array (not the strings it points to) and reassign
    delete[] meanings; 
    meanings = temp_meaning;
}
