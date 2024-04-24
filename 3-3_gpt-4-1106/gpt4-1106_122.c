temp->word = (char*)malloc(sizeof(char));
strcpy(temp->word, word);
Tree *create(char *word) {
    Tree *temp;
    temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right =  NULL;
    temp->val = 1;
    // Allocate enough memory to store the word plus the null terminator
    temp->word = (char*)malloc(strlen(word) + 1);
    // Copy the word into the allocated memory
    strcpy(temp->word, word);
    return temp;
}
while (temp != EOF) {
    temp = getc(fp);
    temp = toupper(temp);
    // ...
}
void zero(Tree *aTree) {
    if (aTree == NULL)
        return;

    zero(aTree->left);
    zero(aTree->right); 
    free(aTree->word); // Free the allocated word
    free(aTree);
}
