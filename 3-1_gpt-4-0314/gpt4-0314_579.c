#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int wordSize = 2;
    char *word = (char *)malloc(wordSize * sizeof(char));
    char ch;

    const char *ListOfWords = "input.txt";
    FILE *InputWords = NULL;
    InputWords = fopen(ListOfWords, "r");

    if (InputWords == NULL)
    {
        printf("Error while opening the file.\n");
        return 0;
    }

    int index = 0;
    while ((ch = fgetc(InputWords)) != EOF)
    {
        if (!isdigit(ch)) // Check if the character is NOT a digit
        {
            if (ch == ' ' || ch == '\n')
            {
                word[index] = '\0'; // Add null terminator
                printf("%s\n", word);
                wordSize = 2;
                index = 0;
                free(word);
                word = (char *)malloc(wordSize * sizeof(char));
            }
            else
            {
                wordSize++;
                word = (char *)realloc(word, wordSize * sizeof(char));
                word[index] = ch; // Add character to the string
                index++;
            }
        }
    }
    fclose(InputWords);
    free(word);
    return 0;
}
