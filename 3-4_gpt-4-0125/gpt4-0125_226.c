#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFSIZE 81

int main(int numParms, char *parms[])
{
    FILE *file;
    char buffer[BUFFSIZE];
    char *token;
    int lineNum = 0;
    
    // Open file for reading
    file = fopen("in.txt", "r"); 
    if (file == NULL) 
    {
        perror("Error opening file");
        return(-1);
    }
    
    // Corrected to read from the file horizontally opened
    while (fgets(buffer, BUFFSIZE, file)) // Continue reading until end of file
    {    
        char bigWord[30] = ""; // Initialize bigWord to an empty string
        int bigSize = 0;
        lineNum++;
        
        token = strtok(buffer, " \n\t"); // Tokenize with space, newline, and tab as delimiters
        while (token != NULL)
        {
            int currSize = strlen(token); // Get current word size
            if (currSize > bigSize)
            {
                strcpy(bigWord, token); // Current word is bigger, so update bigWord
                bigSize = currSize; // Update the size of the biggest word found
            }
            token = strtok(NULL, " \n\t"); // Move to the next token
        }

        if (bigWord[0] != '\0') // Print only if a big word was found (i.e., line is not empty)
        {
            printf("Line %d's word: %s\n", lineNum, bigWord);
        }
    }

    fclose(file); // Close the file

    return(0);
}
