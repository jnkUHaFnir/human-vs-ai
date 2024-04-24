#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadBookName(char* filename, char* authorName[55], char* bookName[55]);

int main(int argc, char* argv[]) {
    char* authorName[55];
    char* bookName[55];

    char fileName[30];
    printf("Please enter the name of the file: ");
    scanf("%s", fileName);

    loadBookName(fileName, authorName, bookName);

    // Print the two arrays
    int i = 0;
    printf("%-30s%-40s\n", "Author", "Book");
    for (i = 0; i < 55; i++) {
        printf("%-30s%-40s\n", authorName[i], bookName[i]);
    }

    return 0;
}

void loadBookName(char* filename, char* authorName[55], char* bookName[55]) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file\n");
        exit(1);
    }

    char string_array[80];
    const char comma[2] = ",";
    
    for (int i = 0; i < 55; i++) {
        fgets(string_array, 80, fp);

        // Tokenize the string to separate author and book
        char* token = strtok(string_array, comma);
        if (token == NULL) {
            printf("Error reading data from the file. Ensure correct format (author, book)\n");
            exit(1);
        }
        authorName[i] = strdup(token); // Allocate memory for author name

        token = strtok(NULL, "\n"); // Get the book title
        if (token == NULL) {
            printf("Error reading book title from the file.\n");
            exit(1);
        }
        bookName[i] = strdup(token); // Allocate memory for book title
    }

    fclose(fp);
}
