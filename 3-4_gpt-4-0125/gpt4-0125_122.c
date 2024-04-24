temp->word = (char*)malloc(sizeof(char));
strcpy(temp->word, word);
temp->word = (char*)malloc(strlen(word) + 1);
if (temp == NULL) {
    // Handle allocation failure
    return NULL;
}
if (temp->word == NULL) {
    free(temp);
    // Handle allocation failure
    return NULL;
}
zero(aTree->left);
free(aTree);
zero(aTree->right);
zero(aTree->left);
zero(aTree->right);
free(aTree->word); // Also remember to free the word
free(aTree);
