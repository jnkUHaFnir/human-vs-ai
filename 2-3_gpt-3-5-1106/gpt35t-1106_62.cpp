void Expression::add_meaning(char *p2c)
{
    // ...
    if (meanings_ctr < 1) {
        meanings[meanings_ctr] = new char[strlen(p2c) + 1];
        strcpy(meanings[meanings_ctr++], p2c);
    } else {
        int temp_ctr;
        char **temp_meaning;
        temp_meaning = new char *[meanings_ctr - 1];
        for (temp_ctr = 0; temp_ctr < meanings_ctr; temp_ctr++) {
            temp_meaning[temp_ctr] = new char[strlen(meanings[temp_ctr]) + 1];
            strcpy(temp_meaning[temp_ctr], meanings[temp_ctr]);
        }
        // ...
    }
}
void Expression::add_meaning(char *p2c)
{
    if (meanings_ctr < 1) {
        meanings[meanings_ctr] = new char[strlen(p2c) + 1];
        strcpy(meanings[meanings_ctr++], p2c);
    } else {
        char **temp_meaning = new char *[meanings_ctr];
        for (int i = 0; i < meanings_ctr; i++) {
            temp_meaning[i] = new char[strlen(meanings[i]) + 1];
            strcpy(temp_meaning[i], meanings[i]);
            delete[] meanings[i];
        }
        delete[] meanings;

        meanings = new char *[meanings_ctr + 1];
        for (int i = 0; i < meanings_ctr; i++) {
            meanings[i] = new char[strlen(temp_meaning[i]) + 1];
            strcpy(meanings[i], temp_meaning[i]);
            delete[] temp_meaning[i];
        }
        delete[] temp_meaning;

        meanings[meanings_ctr] = new char[strlen(p2c) + 1];
        strcpy(meanings[meanings_ctr++], p2c);
    }
}
