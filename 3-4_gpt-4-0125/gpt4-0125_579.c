#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // For isspace

int main() {
    int wordSize = 2; // Starting with an arbitrary size.
    char *word = malloc(wordSize * sizeof(char)); // Allocate initial size
    char ch;

    const char* ListOfWords = "yourfilename.txt"; // Set this to your filename
    FILE* InputWords = fopen(ListOfWords,"r");

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 0;
    }

    int index = 0;
    while((ch = fgetc(InputWords)) != EOF) { // Use EOF instead of -1
        if(isspace(ch) || ch == EOF) { // Check for end of word or file
            if(index > 0) { // There's a word to print
                word[index] = '\0'; // Null-terminate the string
                printf("%s\n", word);

                // Reset for next word
                wordSize = 2;
                index = 0;
                free(word);
                word = malloc(wordSize * sizeof(char)); // Reallocate with initial size
            }
            if(ch == EOF) break; // Break if it's the end of the file
        } else {
            if(index + 1 >= wordSize) {
                // Need more space
                wordSize *= 2; // Double the size for efficiency
                word = realloc(word, wordSize * sizeof(char));
            }
            word[index++] = ch; // Add char to word and increment index
        }
    }

    // Clean up
    free(word);
    fclose(InputWords);

    return 0;
}
