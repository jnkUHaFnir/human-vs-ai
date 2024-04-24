void Expression::add_meaning(char *p2c)
{
    char** temp_meaning = new char*[meanings_ctr + 1];

    // Copy existing meanings to temporary array
    for (int i = 0; i < meanings_ctr; i++)
    {
        temp_meaning[i] = new char[strlen(meanings[i]) + 1];
        strcpy(temp_meaning[i], meanings[i]);
        delete[] meanings[i]; // Free memory of old meanings
    }

    // Add the new meaning
    temp_meaning[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(temp_meaning[meanings_ctr], p2c);

    // Free memory of old meanings array
    delete[] meanings;

    // Update meanings pointer to point to the new array
    meanings = temp_meaning;

    // Increase the counter
    meanings_ctr++;
}
