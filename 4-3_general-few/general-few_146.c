Tree *create(char *word) {
    Tree *temp;
    temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right =  NULL;
    temp->val = 1;
    
    // Allocate memory for the word with space for the null terminator
    temp->word = (char*)malloc(strlen(word) + 1);
    strcpy(temp->word, word);
    
    return temp;
}
