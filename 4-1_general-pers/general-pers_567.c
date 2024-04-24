Tree *create(char *word) {
    Tree *temp;
    // Allocate memory for the Tree struct
    temp = (Tree*)malloc(sizeof(Tree));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    temp->left = NULL;
    temp->right = NULL;
    temp->val = 1;

    // Allocate memory for the word and copy it
    temp->word = (char*)malloc(strlen(word) + 1);
    if (temp->word == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(temp->word, word);

    return temp;
}
