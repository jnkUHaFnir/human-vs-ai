Expression::Expression(int mctr ) {
    meanings_ctr = mctr;
    meanings = new char * [meanings_ctr]();
}

Expression::~Expression() {
    for (int i = 0; i < meanings_ctr; ++i) {
        delete [] meanings[i];
    }
    delete [] meanings;
    delete [] word_with_several_meanings;
}

void Expression::word(const char *p2c) {
    if (word_with_several_meanings) {
        delete [] word_with_several_meanings;
    }
    word_with_several_meanings = new char[strlen(p2c) + 1];
    strcpy(word_with_several_meanings, p2c);
}

void Expression::add_meaning(char *p2c) {
    char** temp_meaning = new char *[meanings_ctr + 1];
    for (int i = 0; i < meanings_ctr; ++i) {
        temp_meaning[i] = new char[strlen(meanings[i]) + 1];
        strcpy(temp_meaning[i], meanings[i]);
        delete [] meanings[i];
    }
    delete [] meanings;
    meanings = temp_meaning;
    
    meanings[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(meanings[meanings_ctr], p2c);
    meanings_ctr++;
}
