#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFSIZE 81

int main(int argc, char *argv[])
{
    FILE *file;
    char buffer[BUFFSIZE];
    char *token;
    int lineNum = 0;
    
    file = fopen("in.txt" , "r");
    if(file == NULL) 
    {
        perror("Error opening file");
        return -1;
    }

    while(fgets(buffer, BUFFSIZE, file) != NULL) 
    {
        char bigWord[30] = {0};
        int bigSize = 0;

        char currWord[30] = {0};
        int currSize = 0;

        token = strtok(buffer, " \n\t");
        while(token != NULL)
        {               
            strcpy(currWord, token);
            currSize = strlen(currWord);
            if(currSize > bigSize)
            {
                strcpy(bigWord, currWord);
                bigSize = currSize;
            }
            token = strtok(NULL, " \n\t");  
        }

        if(bigSize > 0)
        {
            printf("Line %d's biggest word: %s\n", lineNum, bigWord);
        }

        lineNum++;
    }

    fclose(file);

    return 0;
}
