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
        return -1;
    }
    
    while (fgets(buffer, BUFFSIZE, file) != NULL) // Read from the file, not from stdin
    {
        char bigWord[MAX_WORD_SIZE] = "";
        int bigSize = 0;
        
        token = strtok(buffer, " \n\t");
        while (token != NULL)
        {
            char currWord[MAX_WORD_SIZE];
            strncpy(currWord, token, MAX_WORD_SIZE - 1);
            currWord[MAX_WORD_SIZE - 1] = '\0'; // Ensure null-termination
            
            int currSize = strlen(currWord);
            if (currSize > bigSize)
            {
                strcpy(bigWord, currWord);
                bigSize = currSize;
            }
            token = strtok(NULL, " \n\t");
        }
        
        printf("Line %d's biggest word: %s\n", lineNum, bigWord);
        lineNum++;
    }

    fclose(file);

    return 0;
}
