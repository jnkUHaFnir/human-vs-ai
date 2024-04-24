Tree *create(char *word) {
    Tree *temp = (Tree*)malloc(sizeof(Tree));
    if (temp == NULL) {
        // Handle allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    temp->left = temp->right =  NULL;
    temp->val = 1;
    
    // Allocate memory for the word string
    temp->word = (char*)malloc(strlen(word) + 1);
    if (temp->word == NULL) {
        // Handle allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    strcpy(temp->word, word);
    
    return temp;
}
