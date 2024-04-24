void Expression::add_meaning(char *p2c)
{
    if (meanings_ctr >= 0) {
        char **temp_meaning = new char *[meanings_ctr + 1];

        // Copy existing meanings to temp array
        for (int i = 0; i < meanings_ctr; i++) {
            temp_meaning[i] = new char[strlen(meanings[i]) + 1];
            strcpy(temp_meaning[i], meanings[i]);
            delete[] meanings[i]; // Free each meaning as it's copied
        }
        delete[] meanings; // Free the old array

        // Allocate new memory for meanings with updated count
        meanings = temp_meaning;
    }

    // Allocate memory for the new meaning and copy it
    meanings[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(meanings[meanings_ctr], p2c);
    meanings_ctr++;
}
