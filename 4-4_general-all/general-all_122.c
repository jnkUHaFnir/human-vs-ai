temp->word = (char*)malloc(strlen(word) + 1);
int alpha(char *word1, char *word2) {
    if (word1[0] == '\0' && word2[0] == '\0')
        return 2;
    else if (word1[0] == word2[0])
        return alpha(&word1[1], &word2[1]);
    else if (word1[0] < word2[0])
        return 1;
    else
        return 0;
}
void zero(Tree *aTree) {
    if (aTree == NULL)
        return;

    zero(aTree->left);
    free(aTree->word);
    free(aTree);
    aTree->word = NULL;
    aTree = NULL;
    zero(aTree->right);  
}
