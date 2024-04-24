void Expression::add_meaning(char *p2c)
{
    char **temp_meaning = new char *[meanings_ctr + 1];

    for (int i = 0; i < meanings_ctr; i++)
    {
        temp_meaning[i] = new char[strlen(meanings[i]) + 1];
        strcpy(temp_meaning[i], meanings[i]);
        delete[] meanings[i];
    }

    delete[] meanings;

    meanings = temp_meaning;

    meanings[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(meanings[meanings_ctr], p2c);

    meanings_ctr++;
}
