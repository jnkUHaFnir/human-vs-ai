#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int wordSize = 2;
    char *word = (char *)malloc(wordSize * sizeof(char));
    char ch;

    FILE* InputWords = NULL;
    const char* ListOfWords = "example.txt"; // Example file name
    InputWords = fopen(ListOfWords,"r");

    if (InputWords == NULL)
    {
        printf("Error while opening the file.\n");
        return 1;
    }

    int index = 0;
    while((ch = fgetc(InputWords)) != EOF)
    {
        if(ch == ' ' || ch == '\n')
        {
            word[index] = '\0'; // Null-terminate the string
            printf("%s\n", word);
            wordSize = 2;
            index = 0;
            free(word);
            word = (char *)malloc(wordSize * sizeof(char));
        }
        else
        {
            if (index == wordSize - 1) {
                wordSize *= 2;
                word = (char *)realloc(word, wordSize * sizeof(char));
            }
            word[index] = ch;
            index++;
        }
    }
    word[index] = '\0'; // Null-terminate the last word
    printf("%s\n", word);

    free(word);
    fclose(InputWords);

    return 0;
}
