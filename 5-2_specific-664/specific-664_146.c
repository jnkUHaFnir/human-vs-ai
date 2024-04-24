temp->word = (char*)malloc(sizeof(char));
strcpy(temp->word, word);
Tree *create(char *word) {
    Tree *temp;
    temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right =  NULL;
    temp->val = 1;
    temp->word = (char*)malloc(strlen(word) + 1); // +1 for null terminator
    strcpy(temp->word, word);
    return temp;
}
void zero(Tree *aTree) {
    if (aTree == NULL)
        return;

    zero(aTree->left);
    zero(aTree->right);
    
    free(aTree->word); // free the word field
    free(aTree); // then free the node itself
}
