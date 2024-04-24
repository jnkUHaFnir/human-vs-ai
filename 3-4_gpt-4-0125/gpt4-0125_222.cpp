Expression::Expression(int mctr): meanings_ctr(mctr), word_with_several_meanings(nullptr) {
    meanings = new char*[meanings_ctr];
}

Expression::~Expression() {
    for (int i = 0; i < meanings_ctr; ++i) {
        delete[] meanings[i];
    }
    delete[] meanings;
    delete[] word_with_several_meanings;
}
