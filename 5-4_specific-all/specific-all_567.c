Tree *create(char *word) {
    Tree *temp;
    temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right =  NULL;
    temp->val = 1;
    temp->word = (char*)malloc(strlen(word) + 1); // Allocate memory for the entire word
    strcpy(temp->word, word);
    return temp;
}
