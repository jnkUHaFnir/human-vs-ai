Tree *create(char *word) {
    Tree *temp;
    temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right =  NULL;
    temp->val = 1;
    
    // Allocate memory according to the length of the word
    temp->word = (char*)malloc(strlen(word) + 1);
    strcpy(temp->word, word);
    
    return temp;
}
