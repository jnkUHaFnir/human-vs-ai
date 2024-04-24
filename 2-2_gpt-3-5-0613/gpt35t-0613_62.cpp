while(meanings_ctr-->0){
    delete meanings[meanings_ctr];
}
delete [] meanings;
meanings = new char * [meanings_ctr];
delete [] meanings;
Expression::~Expression() {
    for (int i = 0; i < meanings_ctr; i++) {
        delete [] meanings[i]; // Delete each individual meaning
    }
    delete [] meanings; // Delete the "meanings" array
    delete [] word_with_several_meanings; // Delete the word memory
}
