Tree *create(char *word) {
    Tree *temp;
    temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right =  NULL;
    temp->val = 1;
    temp->word = (char*)malloc(sizeof(char)); // This line is wrong
    strcpy(temp->word, word);
    return temp;
}
Tree *create(char *word) {
    Tree *temp;
    temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right =  NULL;
    temp->val = 1;
    temp->word = (char*)malloc((strlen(word) + 1) * sizeof(char)); // Fixed this line
    strcpy(temp->word, word);
    return temp;
}
void zero(Tree *aTree) {
    if (aTree == NULL)
        return;

    zero(aTree->left);
    free(aTree->word); // Add this line
    free(aTree);
    zero(aTree->right);    
}
