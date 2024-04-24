void Expression::add_meaning( char  * p2c){
    char **new_meanings = new char*[meanings_ctr + 1];
    for(int i = 0; i < meanings_ctr; i++){
        new_meanings[i] = meanings[i];
    }
    new_meanings[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(new_meanings[meanings_ctr], p2c);
    delete [] meanings;
    meanings = new_meanings;
    meanings_ctr++;
}
Expression::~Expression() {
    for(int i = 0; i < meanings_ctr; i++){
        delete [] meanings[i];
    }
    delete [] meanings;
    delete [] word_with_several_meanings;
}
