Expression::~Expression() {
    for(int i = 0; i < meanings_ctr; i++) {
        delete [] meanings[i];
    }
    delete [] meanings;
    delete [] word_with_several_meanings;
}
Expression::Expression(int mctr) {
    meanings_ctr = mctr;
    meanings = NULL;         // Initialize to NULL
    meanings = new char * [meanings_ctr];
}
