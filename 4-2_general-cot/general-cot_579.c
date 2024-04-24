#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int wordSize = 2;
    char *word = (char *)malloc(wordSize * sizeof(char));
    char ch;

    FILE* InputWords = NULL;
    InputWords = fopen("ListOfWords.txt","r");

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 1;
    }

    int index = 0;
    while((ch = fgetc(InputWords)) != EOF) {
        if(ch == ' ') {
            word[index] = '\0'; // Null terminate string
            printf("%s\n", word);
            wordSize = 2;
            index = 0;
            free(word);
            word = (char *)malloc(wordSize * sizeof(char));
        } else {
            if(index == wordSize - 1) {
                wordSize *= 2;
                word = (char *)realloc(word, wordSize * sizeof(char));
            }
            word[index] = ch;
            index++;
        }
    }

    word[index] = '\0'; // Print last word
    printf("%s\n", word);

    fclose(InputWords);
    free(word);

    return 0;
}
