Tree *create(char *word) {
    Tree *temp;
    temp = (Tree*)malloc(sizeof(Tree));
    temp->left = temp->right =  NULL;
    temp->val = 1;
    temp->word = (char*)malloc(strlen(word) + 1); // Dynamically allocate memory for the word
    strcpy(temp->word, word);
    return temp;
}

Tree *insert(Tree *aTree, char *word) {
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
    FILE *fp = fopen(argv[1], "r");
    if (fp)  {
        while ((temp = fgetc(fp)) != EOF) {
            temp = toupper(temp);
            if (isalpha(temp)) {
                char buffer[256] = { 0 }; // Allocate buffer for each word
                int i = 0;
                buffer[i] = temp;
                i++;
                while ((temp = fgetc(fp)) != EOF && isalpha(temp) && i < 255) {
                    buffer[i] = toupper(temp);
                    i++;
                }
                
                buffer[i] = '\0'; // Null-terminate the word
                
                puts(buffer);
                myTree = insert(myTree, buffer);
            }
        }
        fclose(fp);
    }
    
    show(myTree);
    
    // Cleanup tree
    zero(myTree);
    
    return 0;
}
