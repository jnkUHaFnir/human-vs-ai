int main(int argc, char *argv[]) {
    Tree *myTree = NULL;
    char temp = 0;
    int i = 0;
    FILE *fp = fopen(argv[1], "r");
    if (fp) {
        char *buffer = (char*)malloc(256 * sizeof(char)); // dynamically allocate memory for each word
        memset(buffer, 0, 256); // clear the buffer

        while ((temp = fgetc(fp)) != EOF) {
            temp = toupper(temp);
            if (isalpha(temp)) {
                buffer[i] = temp;
                i++;
            } else {
                if (i > 0) {
                    buffer[i] = '\0'; // null-terminate the word
                    myTree = insert(myTree, buffer);
                    printf("%s\n", buffer); // print the word
                    i = 0;
                    memset(buffer, 0, 256); // clear the buffer for the next word
                }
            }
        }

        free(buffer); // free dynamically allocated memory for buffer
        fclose(fp);
        show(myTree);
        zero(myTree); // free the tree nodes
    } else {
        printf("Error opening file.\n");
    }

    return 0;
}
