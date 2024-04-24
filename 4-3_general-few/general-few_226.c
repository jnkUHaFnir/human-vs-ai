#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFSIZE 81
#define MAX_WORD_SIZE 30

int main(int numParms, char *parms[])
{
    FILE *file;
    char buffer[BUFFSIZE];
    char *token;
    int lineNum = 0;

    file = fopen("in.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return (-1);
    }

    while (fgets(buffer, BUFFSIZE, file) != NULL)
    {
        char bigWord[MAX_WORD_SIZE];
        int bigSize = 0;

        token = strtok(buffer, " \n\t");
        while (token != NULL)
        {
            if (strlen(token) > bigSize)
            {
                strcpy(bigWord, token);
                bigSize = strlen(bigWord);
            }
            token = strtok(NULL, " \n\t");
        }
        printf("Line %d's biggest word: %s\n", lineNum + 1, bigWord);
        lineNum++;
    }

    fclose(file);

    return 0;
}
