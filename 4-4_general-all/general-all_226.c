#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFSIZE 81
#define MAX_WORD_LENGTH 30

int main(int argc, char *argv[])
{
    FILE *file;
    char buffer[BUFFSIZE];
    char *token;
    int lineNum = 0;

    file = fopen("in.txt", "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return -1;
    }

    while (fgets(buffer, BUFFSIZE, file) != NULL)
    {
        lineNum++;
        char bigWord[MAX_WORD_LENGTH] = "";
        int bigSize = 0;

        token = strtok(buffer, " \n\t");
        while (token != NULL)
        {
            char currWord[MAX_WORD_LENGTH];
            strcpy(currWord, token);
            int currSize = strlen(currWord);

            if (currSize > bigSize)
            {
                strcpy(bigWord, currWord);
                bigSize = currSize;
            }
            token = strtok(NULL, " \n\t");
        }

        if (bigSize > 0)
        {
            printf("Line %d's biggest word: %s\n", lineNum, bigWord);
        }
    }

    fclose(file);

    return 0;
}
