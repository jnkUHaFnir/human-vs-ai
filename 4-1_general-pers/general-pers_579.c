#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main() {
    char* word = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));
    int wordSize = 0;
    
    FILE* InputWords = NULL;
    char ch;

    InputWords = fopen("ListOfWords.txt", "r"); // Update the file name here

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 1;
    }

    while ((ch = fgetc(InputWords)) != EOF) {
        if (isalpha(ch) || ch == '\'') { // Check if the character is a letter or an apostrophe
            word[wordSize++] = ch;
            if (wordSize == MAX_WORD_LENGTH - 1) {
                // Reallocate memory if needed
                word = (char *)realloc(word, 2 * wordSize * sizeof(char));
            }
        } else if (wordSize > 0) { // If the word is complete
            word[wordSize] = '\0'; // Null-terminate the string
            printf("%s\n", word);
            wordSize = 0;
        }
    }

    fclose(InputWords);
    free(word);

    return 0;
}
