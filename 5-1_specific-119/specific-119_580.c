#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE* InputWords = fopen("ListOfWords.txt", "r");
    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 1;
    }

    char *word = NULL;
    size_t wordSize = 0;
    int c;
    int index = 0;

    while ((c = fgetc(InputWords)) != EOF) {
        if (isalpha(c) || c == ' ') {
            if (index == 0) {
                wordSize = 1;
                word = (char *)malloc(wordSize * sizeof(char));
            } else {
                wordSize++;
                word = (char *)realloc(word, wordSize * sizeof(char));
            }
            word[index++] = c;
            word[index] = '\0';
        } else if (index > 0) {
            printf("%s\n", word);
            free(word);
            word = NULL;
            wordSize = 0;
            index = 0;
        }
    }

    if (index > 0) {
        printf("%s\n", word);
        free(word);
    }

    fclose(InputWords);
    return 0;
}
