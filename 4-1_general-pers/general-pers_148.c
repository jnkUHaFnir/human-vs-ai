#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadBookName(char* filename, char* authorName[55], char* bookName[55]);

int main(int argc, char* argv[])
{
    char* authorName[55];
    char* bookName[55];
    char fileName[30];

    printf("Please enter the name of the file: ");
    scanf("%s", fileName);

    loadBookName(fileName, authorName, bookName);

    // Print the two arrays to test if the two arrays were correctly loaded with the data
    int i = 0;
    printf("%-30s%-40s\n", "Author", "Book");
    for (i = 0; i < 55; i++) {
        printf("%-30s%-40s\n", authorName[i], bookName[i]);
    }

    return 0;
}

void loadBookName(char* filename, char* authorName[55], char* bookName[55])
{
    int i;
    char string_array[80];
    const char comma[2] = ",";

    FILE* fp;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Failed to open file\n");
        exit(1);
    }

    for (i = 0; i < 55; i++)
    {
        fgets(string_array, 80, fp);

        // Tokenize the string using comma as the delimiter
        authorName[i] = strtok(string_array, comma);
        bookName[i] = strtok(NULL, ")");
        
        // Check for potential buffer overflow by ensuring bookName is not NULL
        if (bookName[i] == NULL) {
            printf("Error: Invalid format in the file.\n");
            exit(1);
        }

        // Remove leading space from bookName
        if (bookName[i][0] == ' ') {
            bookName[i]++;
        }

        printf("Author: %s, Book: %s\n", authorName[i], bookName[i]);
    }

    fclose(fp);
}
