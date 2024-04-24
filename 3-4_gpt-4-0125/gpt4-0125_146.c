Tree *create(char *word) {
    Tree *temp;
    temp = (Tree*)malloc(sizeof(Tree));
    if (temp == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    temp->left = temp->right =  NULL;
    temp->val = 1;
    
    // Allocate memory for the whole word, including the null terminator
    temp->word = (char*)malloc(strlen(word) + 1); 
    if (temp->word == NULL) {
        fprintf(stderr, "Out of memory\n");
        free(temp); // Make sure to free already allocated memory to avoid leaks
        exit(1);
    }
    strcpy(temp->word, word); // Copy the word into the allocated space
    return temp;
}
// After reading from file
if (fp) { 
    // Reading loop here
    fclose(fp); // Make sure fclose is inside if-block to prevent closing an invalid pointer
} else {
    perror("File opening failed");
    return EXIT_FAILURE;
}
void zero(Tree *aTree) {
    if (aTree == NULL)
        return;

    zero(aTree->left);
    zero(aTree->right);
    free(aTree->word); // Free the string memory first
    free(aTree); // Then free the node
}
