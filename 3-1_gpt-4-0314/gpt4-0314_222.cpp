Expression::~Expression() {
    while(meanings_ctr-- > 0) {
        delete meanings[meanings_ctr];
    }
    delete meanings;
    delete [] word_with_several_meanings;
}
void Expression::add_meaning(char *p2c) {
    // ... other code ...
    delete meanings;
    // ... other code ...
    delete temp_meaning;
    meanings_ctr++;
}
