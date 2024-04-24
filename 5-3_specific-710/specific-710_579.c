#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int wordSize = 2;
    char *word = (char *)malloc(wordSize*sizeof(char));
    char ch;

    FILE* InputWords = NULL;
    InputWords = fopen("ListOfWords.txt","r"); /* Assuming "ListOfWords.txt" is the name of the file */

    if (InputWords == NULL)
    {
      printf("Error while opening the file.\n");
      return 0;
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
            word = (char *)malloc(wordSize*sizeof(char));
        }
        else
        {
            if (index >= wordSize - 1)
            {
                wordSize *= 2;
                word = (char *)realloc(word, wordSize*sizeof(char));
            }
            word[index] = ch;
            index++;
        }
    }

    fclose(InputWords);
    free(word); // Free the memory allocated for the last word

    return 0;
}
