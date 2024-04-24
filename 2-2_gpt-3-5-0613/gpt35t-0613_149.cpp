Expression::~Expression() {
    if (meanings) {
        for (int i = 0; i < meanings_ctr; i++) {
            delete[] meanings[i];
        }
        delete[] meanings;
    }
    delete[] word_with_several_meanings;
}
