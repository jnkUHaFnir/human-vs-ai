int main(int argc, char *argv[]) {
    Tree *myTree = NULL;
    char buffer[256] = {0};
    int i = 0;
    FILE *fp = fopen(argv[1], "r");
    
    if (fp)  {
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            char *word = strtok(buffer, " \t\n"); // extract first word from line
            while (word != NULL) {
                // Convert word to uppercase
                for (int j = 0; word[j]; j++) {
                    word[j] = toupper(word[j]);
                }
                
                // Insert uppercase word into the tree
                if (strlen(word) > 0) {
                    myTree = insert(myTree, word);
                }

                word = strtok(NULL, " \t\n"); // extract next word from line
            }
        }
        fclose(fp);
    }

    show(myTree);
    zero(myTree); // Free allocated memory before exiting
    return 0;
}
