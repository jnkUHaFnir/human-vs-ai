#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* InputWords = NULL;
    char ListOfWords[] = "your_file.txt"; // Update with your file name
    InputWords = fopen(ListOfWords, "r");

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 1; // Return 1 to indicate error
    }

    int wordSize = 2; // Initial size for the word
    char* word = (char *)malloc(wordSize * sizeof(char));
    int index = 0;
    char ch;

    while ((ch = fgetc(InputWords)) != EOF) {
        if (ch == ' ' || ch == '\n') { // Assuming space or newline marks end of word
            if (index > 0) { // Print and reset word if it's not empty
                word[index] = '\0'; // Add null terminator
                printf("%s\n", word);
            }
            index = 0;
        } else { // Append character to the word
            if (index == wordSize - 1) { // Resize word if needed
                wordSize *= 2;
                word = realloc(word, wordSize * sizeof(char));
            }
            word[index] = ch;
            index++;
        }
    }

    // Print the last word if any
    if (index > 0) {
        word[index] = '\0'; // Add null terminator
        printf("%s\n", word);
    }

    free(word); // Free allocated memory
    fclose(InputWords);

    return 0; // Return 0 to indicate success
}
