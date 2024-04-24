#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int wordSize = 2;
    char *word = (char *)malloc(wordSize * sizeof(char));
    char ch;
    int index = 0;

    FILE* InputWords = NULL;
    char ListOfWords[] = "words.txt"; // Example filename
    InputWords = fopen(ListOfWords, "r");

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 1;
    }

    while ((ch = fgetc(InputWords)) != EOF) {
        if (ch == ' ') {
            word[index] = '\0'; // Add null terminator to make it a string
            if (strlen(word) > 0) { // Check if word contains any characters
                printf("%s\n", word);
            }
            wordSize = 2;
            index = 0;
            free(word);
            word = (char *)malloc(wordSize * sizeof(char));
        } else {
            if (ch >= '0' && ch <= '9') {
                // Skip numbers
                continue;
            }
            word[index] = ch;
            index++;
            
            if (index >= wordSize - 1) {
                wordSize *= 2;
                word = (char *)realloc(word, wordSize * sizeof(char));
            }
        }
    }

    word[index] = '\0'; // Add null terminator for the last word
    if (strlen(word) > 0) {
        printf("%s\n", word);
    }

    fclose(InputWords);
    free(word);

    return 0;
}
