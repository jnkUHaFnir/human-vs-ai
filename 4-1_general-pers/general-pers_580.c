#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE* InputWords = NULL;
    char *ListOfWords = "example.txt"; // assuming example filename
    InputWords = fopen(ListOfWords, "r");

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 1;
    }

    int wordSize = 2;
    char *word = (char *)malloc(wordSize * sizeof(char));
    char ch;
    int index = 0;

    if (word == NULL) {
        printf("Memory allocation error.\n");
        fclose(InputWords);
        return 1;
    }

    while ((ch = fgetc(InputWords)) != EOF) {
        if (isspace(ch)) { // check for space and handle the word
            if (index > 0) { // if it's a word, not just spaces
                word[index] = '\0'; // null-terminate the string
                printf("%s\n", word);
            }
            index = 0; // reset for the next word
        } else if (isalpha(ch)) { // only store alphabetic characters
            if (index == wordSize - 1) {
                wordSize *= 2;
                word = (char *)realloc(word, wordSize * sizeof(char));
                if (word == NULL) {
                    printf("Memory allocation error.\n");
                    fclose(InputWords);
                    return 1;
                }
            }
            word[index++] = ch;
        }
    }

    if (index > 0) { // print the last word if not printed
        word[index] = '\0'; // null-terminate the string
        printf("%s\n", word);
    }

    free(word);
    fclose(InputWords);

    return 0;
}
