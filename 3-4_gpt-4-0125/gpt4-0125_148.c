#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadBookName(char* filename, char* authorName[55], char* bookName[55]);

int main() {
    char* authorName[55];
    char* bookName[55];
    char fileName[30];

    printf("Please enter the name of the file\n");
    scanf("%29s", fileName); // Limit input to prevent overflow

    loadBookName(fileName, authorName, bookName);

    printf("%-30s%-40s\n", "Author", "Book");
    for (int i = 0; i < 55; i++) {
        printf("%-30s%-40s\n", authorName[i], bookName[i]);
        // Free allocated memory
        free(authorName[i]);
        free(bookName[i]);
    }

    return 0;
}

void loadBookName(char* filename, char* authorName[55], char* bookName[55]) {
    char string_array[80];
    const char comma[2] = ",";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    for (int i = 0; i < 55 && fgets(string_array, 80, fp) != NULL; i++) {
        char *token = strtok(string_array, comma); // Get author
        if (token) {
            authorName[i] = malloc(strlen(token) + 1); // +1 for the null terminator
            strcpy(authorName[i], token);
        }
        token = strtok(NULL, "\n"); // Get book title, assuming newline is delimiter
        if (token) {
            bookName[i] = malloc(strlen(token) + 1);
            strcpy(bookName[i], token);
        }
    }
    fclose(fp);    
}
