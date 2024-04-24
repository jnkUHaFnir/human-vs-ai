#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 55

void loadBookName(char* filename, char* authorName[], char* bookName[]);

int main(int argc, char* argv[]) {
    char* authorName[MAX_ITEMS];
    char* bookName[MAX_ITEMS];
    char fileName[30];

    printf("Please enter the name of the file: ");
    scanf("%s", fileName);

    loadBookName(fileName, authorName, bookName);

    // Print the two arrays to test if the data was loaded correctly
    printf("%-30s%-40s\n", "Author", "Book");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%-30s%-40s\n", authorName[i], bookName[i]);
    }

    return 0;
}

void loadBookName(char* filename, char* authorName[], char* bookName[]) {
    FILE *fp;
    char string_array[80];
    const char comma[2] = ",";
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        fgets(string_array, sizeof(string_array), fp);

        // Tokenize the string to extract author and book title
        authorName[i] = strtok(string_array, comma);
        if (authorName[i] != NULL) {
            // Skip leading whitespaces if any
            bookName[i] = strtok(NULL, comma);
            if (bookName[i] != NULL) {
                // Remove trailing newline characters
                if (bookName[i][strlen(bookName[i]) - 1] == '\n') {
                    bookName[i][strlen(bookName[i]) - 1] = '\0';
                }
            }
        }
    }

    fclose(fp);
}
