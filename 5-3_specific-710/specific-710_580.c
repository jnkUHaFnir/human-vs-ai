#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE* InputWords = NULL;
    char *ListOfWords = "input.txt"; // Example file name

    InputWords = fopen(ListOfWords, "r");
    if (InputWords == NULL) {
      printf("Error while opening the file.\n");
      return 1;
    }

    char *word = NULL;
    size_t wordSize = 0;

    int c;
    while ((c = fgetc(InputWords)) != EOF) {
        if (isalpha(c)) { // Check if the character is a letter
            size_t length = wordSize + 1;
            char *temp = (char *)realloc(word, length + 1); // Allocate space for the new character and null terminator
            if (temp == NULL) {
                free(word);
                printf("Memory allocation failed.\n");
                return 1;
            }
            word = temp;
            word[wordSize] = (char)c;
            word[wordSize + 1] = '\0'; // Null-terminate the string
            wordSize++;
        } else if (wordSize > 0) { // If a word has been found
            printf("%s\n", word);
            free(word);
            word = NULL;
            wordSize = 0;
        }
    }

    if (wordSize > 0) {
        printf("%s\n", word); // Print the last word if exists
        free(word);
    }

    fclose(InputWords);
    return 0;
}
