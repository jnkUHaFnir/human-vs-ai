Tree *create(char *word) {
    Tree *temp;
    temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right =  NULL;
    temp->val = 1;
    // Dynamically allocate memory for the word based on its length
    temp->word = (char*)malloc(strlen(word) + 1);
    strcpy(temp->word, word);
    return temp;
}
