void loadBookName(char* filename, char* authorName[55], char* bookName[55])
{
    int i;
    char string_array[80];
    const char comma[2] = ",";

    // Open the file
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Failed to open file\n");
        exit(1);
    }

    for (i = 0; i < 55; i++)
    {
        fgets(string_array, 80, fp);
        
        // Tokenize the string using strtok
        authorName[i] = strtok(string_array, comma);
        bookName[i] = strtok(NULL, "\n"); // Use "\n" as delimiter to get the book title
    }

    // Close the file
    fclose(fp);
}
