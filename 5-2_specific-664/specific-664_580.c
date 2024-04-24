#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int wordSize = 2;
    char *word = (char *)malloc(wordSize * sizeof(char));
    char ch;

    FILE* InputWords = NULL;
    InputWords = fopen("ListOfWords.txt", "r");

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 1;
    }

    int index = 0;
    while ((ch = fgetc(InputWords)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            word[index] = '\0'; // Null-terminate the word
            if (strlen(word) > 0) { // Skip empty words
                printf("%s\n", word);
            }
            wordSize = 2;
            index = 0;
            free(word);
            word = (char *)malloc(wordSize * sizeof(char));
        } else {
            word[index] = ch;
            index++;
            if (index >= wordSize) {
                wordSize *= 2;
                word = (char *)realloc(word, wordSize * sizeof(char));
            }
        }
    }

    fclose(InputWords);
    free(word); // Don't forget to free the memory allocated

    return 0;
}
