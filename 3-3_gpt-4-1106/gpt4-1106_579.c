#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isalpha

int main(int argc, char **argv) {
    // Ensure file name is provided via command line arguments
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 1;
    }

    const char *ListOfWords = argv[1];
    int wordSize = 1; // Start with space for the terminating null byte
    char *word = malloc(wordSize * sizeof(char));
    if (word == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    FILE *InputWords = NULL;
    InputWords = fopen(ListOfWords, "r");
    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        free(word); // Don't forget to free the allocated memory
        return 1;
    }

    int index = 0;
    int ch;

    while ((ch = fgetc(InputWords)) != EOF) {
        if (isalpha(ch)) { // Check if the character is a letter
            if (index + 1 >= wordSize) { // +1 for the null-terminator
                wordSize++;
                word = realloc(word, wordSize * sizeof(char));
                
                if (word == NULL) {
                    printf("Re-allocation failed.\n");
                    fclose(InputWords);
                    return 1;
                }
            }
            word[index++] = (char) ch;
        } else if (ch == ' ' || ch == '\n' || ch == '\r') {
            // End current word if it has content
            if (index > 0) {
                word[index] = '\0'; // End the string
                printf("%s\n", word);
                index = 0;
                wordSize = 1; // Reset size for the next word, enough for null byte
                word = realloc(word, wordSize * sizeof(char));
                if (word == NULL) {
                    printf("Re-allocation failed.\n");
                    fclose(InputWords);
                    return 1;
                }
            }
        }
    }

    // If the last word in the file does not followed by a space or newline
    if (index > 0) {
        word[index] = '\0';
        printf("%s\n", word);
    }
    
    fclose(InputWords);
    free(word);

    return 0;
}
