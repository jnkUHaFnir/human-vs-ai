Tree *insert(Tree *aTree, const char *word) {
    if (aTree == NULL) {
        aTree = create(word);
    } else if (alpha(aTree->word, word) == 0) {
        aTree->left = insert(aTree->left, word);
    } else if (alpha(aTree->word, word) == 1) {
        aTree->right = insert(aTree->right, word);
    } else if (alpha(aTree->word, word) == 2) {
        aTree->val++;
    }
    return aTree;
}

int main(int argc, char *argv[]) {
    Tree *myTree = NULL;
    char temp = 0;
    int i = 0;
    char *word = (char*)malloc(256 * sizeof(char)); // Dynamically allocate memory for each word
    FILE *fp = fopen(argv[1], "r");
    if (fp)  {
        while ((temp = getc(fp)) != EOF) {
            temp = toupper(temp);
            if (isalpha(temp)) {
                word[i] = temp;
                i++;
            } else {
                if (i > 0) {
                    word[i] = '\0';
                    puts(word);
                    myTree = insert(myTree, word);
                    // Dynamically allocate new memory for the next word
                    word = (char*)malloc(256 * sizeof(char));
                    i = 0;
                }
            }
        }
        free(word); // Free the last dynamically allocated memory
    }
    fclose(fp);
    show(myTree);
    zero(myTree); // Free the memory of the binary tree
    return 0;
}
