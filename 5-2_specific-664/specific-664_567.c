Tree *create(char *word) {
    Tree *temp;
    temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right = NULL;
    temp->val = 1;
    temp->word = (char*)malloc(strlen(word) + 1); // Allocate memory for the word
    strcpy(temp->word, word);
    return temp;
}
void zero(Tree *aTree) {
    if (aTree == NULL)
        return;

    zero(aTree->left);
    zero(aTree->right);
    
    free(aTree->word); // Free the memory allocated for the word
    free(aTree);
}
