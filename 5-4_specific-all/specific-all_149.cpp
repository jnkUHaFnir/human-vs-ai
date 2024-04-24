void Expression::add_meaning(char *p2c)
{
    if (meanings_ctr < 1)
    {
        meanings[meanings_ctr] = new char[strlen(p2c) + 1];
        strcpy(meanings[meanings_ctr++], p2c);
    }
    else
    {
        char **temp_meaning = new char *[meanings_ctr]; // Temporary array to hold current meanings

        // Copy current meanings to temp array
        for (int i = 0; i < meanings_ctr; i++)
        {
            temp_meaning[i] = new char[strlen(meanings[i]) + 1];
            strcpy(temp_meaning[i], meanings[i]);
            delete[] meanings[i]; // Delete current meanings
        }
        delete[] meanings;

        // Increase size of meanings array and copy back the temp array
        meanings = new char *[meanings_ctr + 1];
        for (int i = 0; i < meanings_ctr; i++)
        {
            meanings[i] = new char[strlen(temp_meaning[i]) + 1];
            strcpy(meanings[i], temp_meaning[i]);
            delete[] temp_meaning[i]; // Delete temp array
        }
        delete[] temp_meaning;

        meanings[meanings_ctr] = new char[strlen(p2c) + 1];
        strcpy(meanings[meanings_ctr++], p2c);
    }
}
