#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int wordSize = 2;
    char *word = (char *)malloc(wordSize*sizeof(char));
    char ch;

    FILE* InputWords = NULL;
    InputWords = fopen("ListOfWords.txt", "r");

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 1;
    }

    int index = 0;
    while((ch = fgetc(InputWords)) != EOF) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (index >= wordSize - 1) {
                wordSize *= 2;
                word = realloc(word, wordSize*sizeof(char));
            }
            word[index++] = ch;
        } else if (index > 0) {
            word[index] = '\0'; // Null-terminate the string
            printf("%s\n", word);
            wordSize = 2;
            index = 0;
        }
    }

    if (index > 0) {
        word[index] = '\0'; // Null-terminate the last string
        printf("%s\n", word);
    }

    free(word);
    fclose(InputWords);
    
    return 0;
}
