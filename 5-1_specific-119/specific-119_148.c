void loadBookName(char* filename, char* authorName[55], char* bookName[55])
{
    FILE *fp;
    char line[255]; // Increased buffer size to safely read lines
    
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Failed to open file\n");
        exit(1);
    }

    int i = 0;
    while (i < 55 && fgets(line, sizeof(line), fp) != NULL)
    {
        char* token = strtok(line, ",");
        if (token != NULL)
        {
            authorName[i] = malloc(strlen(token) + 1);
            strcpy(authorName[i], token);
        }

        token = strtok(NULL, ","); // Move to the next token
        if (token != NULL)
        {
            bookName[i] = malloc(strlen(token) + 1);
            strcpy(bookName[i], token);
        }

        i++;
    }

    // Close the file
    fclose(fp);
}
