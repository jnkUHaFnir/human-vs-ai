void Expression::add_meaning(char *p2c)
{
    if (meanings_ctr >= 0)
    {
        // Create a new array of pointers with increased size
        char **new_meanings = new char *[meanings_ctr + 1];

        // Copy existing meanings to the new array
        for (int i = 0; i < meanings_ctr; i++)
        {
            new_meanings[i] = new char[strlen(meanings[i]) + 1];
            strcpy(new_meanings[i], meanings[i]);
            delete[] meanings[i]; // Free memory for previous meanings
        }

        // Add the new meaning at the end
        new_meanings[meanings_ctr] = new char[strlen(p2c) + 1];
        strcpy(new_meanings[meanings_ctr], p2c);

        // Free memory for the previous meanings array
        delete[] meanings;

        // Update the meanings pointer to point to the new array
        meanings = new_meanings;
        meanings_ctr++;
    }
}
