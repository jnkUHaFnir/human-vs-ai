#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 30

int main()
{
    printf("Type the name of a file to be read (30 characters max): ");
    char fileName[MAX_FILENAME_LENGTH];
    fgets(fileName, MAX_FILENAME_LENGTH, stdin);
    fileName[strcspn(fileName, "\n")] = 0; // Remove trailing newline

    printf("Type the name of the destination file (30 characters max): ");
    char fileNameW[MAX_FILENAME_LENGTH];
    fgets(fileNameW, MAX_FILENAME_LENGTH, stdin);
    fileNameW[strcspn(fileNameW, "\n")] = 0; // Remove trailing newline

    FILE *fPointerForWriting = fopen(fileNameW, "w");
    FILE *fPointer = fopen(fileName, "r");

    if (fPointer == NULL || fPointerForWriting == NULL)
    {
        printf("Error opening file\n");
        return -1;
    }

    int i = 1;
    char singleLineContent[150];

    while (fgets(singleLineContent, 150, fPointer))
    {
        char *token = strtok(singleLineContent, ",\n");
        fprintf(fPointerForWriting, "%d", atoi(token));
        token = strtok(NULL, ",\n");
        fprintf(fPointerForWriting, ",%d     %d\n", atoi(token), i);
        if (token == NULL)
        {
            printf("There are no tokens\n");
            return -3;
        }
        i++;
    }

    fclose(fPointerForWriting);
    fclose(fPointer);

    return 0;
}
