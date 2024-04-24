temp->word = (char*)malloc(sizeof(char));
temp->word = (char*)malloc(strlen(word) + 1);
Tree *create(char *word) {
    Tree *temp;
    temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right =  NULL;
    temp->val = 1;
    temp->word = (char*)malloc(strlen(word) + 1);
    strcpy(temp->word, word);
    return temp;
}
