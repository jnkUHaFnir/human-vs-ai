#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE* InputWords = NULL;
    InputWords = fopen("ListOfWords.txt", "r"); // Assuming "ListOfWords.txt" is the name of your file

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 1;
    }

    char *word = NULL;
    size_t wordSize = 0;
    
    int ch;
    while ((ch = fgetc(InputWords)) != EOF) {
        if (isalpha(ch) || ch == ' ') {
            wordSize++;
            word = (char *)realloc(word, wordSize * sizeof(char));
            if (word == NULL) {
                printf("Memory reallocation failed.\n");
                return 1;
            }
            word[wordSize - 1] = (char)ch;
        } else {
            if (wordSize > 0) {
                word = (char *)realloc(word, (wordSize + 1) * sizeof(char));
                word[wordSize] = '\0'; // Null-terminate the string
                printf("%s\n", word);
                wordSize = 0;
                free(word);
                word = NULL;
            }
        }
    }

    fclose(InputWords);

    free(word); // Free the allocated memory

    return 0;
}
