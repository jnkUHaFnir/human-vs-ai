void Expression::add_meaning(char *p2c) {

    char **temp_meaning = new char *[meanings_ctr + 1]; // Allocate memory for new meanings array

    for (int i = 0; i < meanings_ctr; i++) {
        temp_meaning[i] = new char[strlen(meanings[i]) + 1]; // Allocate memory for each previous meaning
        strcpy(temp_meaning[i], meanings[i]); // Copy old meanings to new array
        delete [] meanings[i]; // Delete old memory for each meaning
    }

    temp_meaning[meanings_ctr] = new char[strlen(p2c) + 1]; // Allocate memory for new meaning
    strcpy(temp_meaning[meanings_ctr], p2c); // Copy new meaning to new array

    // Delete old memory for meanings array
    delete [] meanings;

    // Update meanings array to point to the new meanings array
    meanings = temp_meaning;
    meanings_ctr++; // Increment meanings counter
}
Expression::Expression(int mctr) {
    meanings_ctr = mctr; // Setting the counter to 0
    meanings = new char *[meanings_ctr]; // Allocate Space for meanings
    for (int i = 0; i < meanings_ctr; i++) {
        meanings[i] = nullptr; // Initialize each element to nullptr
    }
}
