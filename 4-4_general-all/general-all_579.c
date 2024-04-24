#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int wordSize = 2;
    char* word = (char *)malloc(wordSize * sizeof(char));
    char ch;
    int index = 0;

    FILE* InputWords = NULL;
    InputWords = fopen("ListOfWords.txt", "r"); // Use the actual filename instead of ListOfWords

    if (InputWords == NULL) {
        printf("Error while opening the file.\n");
        return 1;
    }

    while((ch = fgetc(InputWords)) != EOF) { // Use EOF to check for end of file
        if (ch == ' ' || ch == '\n') {
            word[index] = '\0'; // Add null terminator to make it a valid C string
            if (strlen(word) > 0) { // Check if word is not empty
                printf("%s\n", word);
            }
            wordSize = 2;
            index = 0;
            free(word);
            word = (char *)malloc(wordSize * sizeof(char));
        } else {
            if (index >= wordSize - 1) { // Check if more space is needed
                wordSize *= 2;
                word = (char *)realloc(word, wordSize * sizeof(char));
            }
            word[index] = ch;
            index++;
        }
    }

    fclose(InputWords);

    free(word); // Free the memory allocated for the last word
    return 0;
}
