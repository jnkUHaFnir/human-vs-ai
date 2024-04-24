#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int wordSize = 2;
    char *word = (char *)malloc(wordSize * sizeof(char));
    char ch;
    int index = 0;

    FILE* InputWords = fopen("ListOfWords.txt", "r"); /* Example file name */

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 0;
    }

    while ((ch = fgetc(InputWords)) != EOF) {
        if (ch == ' ') {
            word[index] = '\0'; // Null-terminate the string
            printf("%s\n", word);
            wordSize = 2;
            index = 0;
            free(word);
            word = (char *)malloc(wordSize * sizeof(char));
        } else {
            if (index == wordSize - 1) {
                wordSize *= 2;
                word = (char *)realloc(word, wordSize * sizeof(char));
            }
            word[index++] = ch;
        }
    }

    word[index] = '\0'; // Null-terminate the last word
    printf("%s\n", word);

    fclose(InputWords);
    free(word);
    return 0;
}
