Tree *create(char *word) {
    Tree *temp = (Tree*)malloc(sizeof(Tree));
    if (temp == NULL) {
        // handle malloc failure here
        return NULL;
    }
    
    temp->left = NULL;
    temp->right = NULL;
    temp->val = 1;
    
    size_t word_length = strlen(word) + 1; // Add 1 for the null terminator
    temp->word = (char*)malloc(word_length * sizeof(char));
    
    if (temp->word == NULL) {
        // handle malloc failure here
        free(temp);
        return NULL;
    }
    
    strcpy(temp->word, word);
    return temp;
}
void zero(Tree *aTree) {
    if (aTree == NULL)
        return;

    zero(aTree->left);
    zero(aTree->right);
    free(aTree->word);
    free(aTree);
}
