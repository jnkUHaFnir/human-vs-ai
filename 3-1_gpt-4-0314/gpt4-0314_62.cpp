void Expression::add_meaning(char *p2c)
{
    meanings = (char **)realloc(meanings, (meanings_ctr + 1) * sizeof(char *));
    meanings[meanings_ctr] = new char[strlen(p2c) + 1];
    strcpy(meanings[meanings_ctr++], p2c);
}
Expression::Expression(int mctr) {
    meanings_ctr = mctr; // Setting the counter to 0
    meanings = (char **)malloc(meanings_ctr * sizeof(char *)); // Allocate Space for meanings
}
Expression::~Expression() {
    while (meanings_ctr-- > 0) {
        delete meanings[meanings_ctr];
    }
    free(meanings); // Freeing the memory we allocated
    delete[] word_with_several_meanings; // Deleting the memory we allocated
}
