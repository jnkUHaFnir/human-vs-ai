Expression::Expression(int mctr ) {
    meanings_ctr = mctr;
    meanings = new char*[meanings_ctr];
    for(int i=0; i<meanings_ctr; i++){
        meanings[i] = NULL;
    }
    word_with_several_meanings = NULL;
}

Expression::~Expression() {
    if(meanings != NULL){
        for(int i=0; i<meanings_ctr; i++){
            if(meanings[i] != NULL){
                delete[] meanings[i];
            }
        }
        delete[] meanings;
    }
    if(word_with_several_meanings != NULL){
        delete[] word_with_several_meanings;
    }
}
