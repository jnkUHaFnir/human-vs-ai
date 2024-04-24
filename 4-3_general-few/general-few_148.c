void loadBookName(char* filename, char* authorName[55], char* bookName[55]) {
    FILE *fp;
    char line[100]; // Adjust size according to the maximum expected length of a line in your file
    const char comma[2] = ",";
    int i = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp) && i < 55) {
        // Tokenize the line to separate author name and book title
        char* token = strtok(line, comma);
        authorName[i] = strdup(token); // strdup allocates memory for the string
        token = strtok(NULL, comma); // Move to the next token
        if (token != NULL) {
            // Remove newline character if present
            token[strcspn(token, "\n")] = 0;
            bookName[i] = strdup(token); // strdup allocates memory for the string
        } else {
            // Handle case where there is no book title
            bookName[i] = "No Title provided";
        }
        i++;
    }

    fclose(fp);
}
