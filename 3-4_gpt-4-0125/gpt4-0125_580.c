#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // for isalpha()

int main() {
    
    const char *ListOfWords = "path_to_your_file.txt"; // Make sure to replace this with your actual file path
    FILE *InputWords = fopen(ListOfWords,"r");
    if (InputWords == NULL)
    {
        printf("Error while opening the file.\n");
        return 0;
    }
    
    char ch;
    int wordSize = 1; // Start with space for the null-terminator
    char *word = (char *)malloc(wordSize * sizeof(char));
    if(!word) return 1; // Always check if malloc was successful
    word[0] = '\0'; // Initialize the string to be empty.

    while((ch = fgetc(InputWords)) != EOF) {
        if(isalpha(ch)) { // Check if the character is a letter
            wordSize++;
            char *newWord = (char *)realloc(word, wordSize * sizeof(char));
            if(!newWord) {
                free(word); // On failure, free the original block
                fclose(InputWords);
                return 1;
            }
            word = newWord;
            word[wordSize-2] = ch;  // Add the new character before the null-terminator
            word[wordSize-1] = '\0'; // Ensure the string is null-terminated
        } else if(ch == ' ' || ch == '\n') { // When encountering a space or newline, print the word if it's not empty
            if(wordSize > 1) { // This checks if we actually collected some characters
                printf("%s\n", word);
                wordSize = 1; // Reset to just null-terminator space
                free(word);
                word = (char *)malloc(wordSize * sizeof(char));
                if(!word) return 1; // Always check malloc success
                word[0] = '\0'; // Reinitialize
            }
        }
    }

    // Print the last word if the file didn't end with a space/newline
    if(wordSize > 1) {
        printf("%s\n", word);
    }

    // Clean up
    free(word);
    fclose(InputWords);
    
    return 0;
}
