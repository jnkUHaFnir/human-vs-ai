Expression::~Expression() {

    for (int i = 0; i < meanings_ctr; i++) {
        delete[] meanings[i];
    }
    delete[] meanings;
    delete[] word_with_several_meanings;
}
void Expression::add_meaning( char  * p2c)
{

    // temp 
    if (meanings_ctr < 1) {
        meanings[meanings_ctr] = new char[strlen(p2c) + 1];
        strcpy(meanings[meanings_ctr++], p2c);
    }
    else {
        int temp_ctr;
        char **temp_meaning;
        temp_meaning = new char*[meanings_ctr + 1];

        for (temp_ctr = 0; temp_ctr < meanings_ctr; temp_ctr++) {
            temp_meaning[temp_ctr] = new char[strlen(meanings[temp_ctr]) + 1];
            strcpy(temp_meaning[temp_ctr], meanings[temp_ctr]);
        }

        temp_meaning[meanings_ctr] = new char[strlen(p2c) + 1];
        strcpy(temp_meaning[meanings_ctr], p2c);

        for (temp_ctr = 0; temp_ctr < meanings_ctr; temp_ctr++) {
            delete[] meanings[temp_ctr];
        }
        delete[] meanings;

        meanings = temp_meaning;
        meanings_ctr++;
    }
}
