Expression::~Expression() {

    for(int i = 0; i < meanings_ctr; ++i) {
        delete [] meanings[i];
    }
    delete [] meanings; // Deleting the memory we allocated
    delete [] word_with_several_meanings; // Deleting the memory we allocated
}
