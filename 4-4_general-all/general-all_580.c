#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main() {
    int wordSize = 2;
    char *word = (char *)malloc(wordSize * sizeof(char));

    FILE* InputWords = NULL;
    InputWords = fopen("ListOfWords.txt", "r"); /* Assuming "ListOfWords.txt" is the file name */

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 1;
    }

    int index = 0;
    char ch;

    while((ch = fgetc(InputWords)) != EOF) {
        if(ch == ' ' || ch == '\n' || ch == '\t') {
            if (index > 0) {
                word[index] = '\0';
                if (strcspn(word, "0123456789") == strlen(word)) {
                    printf("%s\n", word);
                }
                index = 0;
            }
        }
        else {
            if (isalpha(ch) || ch == '\'') { // Allow letters and apostrophes for words
                if (index == wordSize-1) {
                    wordSize *= 2;
                    word = (char *)realloc(word, wordSize * sizeof(char));
                }
                word[index] = ch;
                index++;
            }
            // Ignoring numeric characters
        }
    }

    if (index > 0) {
        word[index] = '\0';
        if (strcspn(word, "0123456789") == strlen(word)) {
            printf("%s\n", word);
        }
    }
    
    free(word);
    fclose(InputWords);
    return 0;
}
