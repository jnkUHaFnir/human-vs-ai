#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("Type the name of a file to be read (30 character max): ");
    char fileName[30];
    scanf("%s", fileName);
    printf("Type the name of destination file (30 character max): ");
    char fileNameW[30];
    scanf("%s", fileNameW);
    FILE *fPointerForWriting = fopen(fileNameW, "w");
    FILE *fPointer = fopen(fileName, "r");

    if (fPointer == NULL || fPointerForWriting == NULL)
    {
        perror("Error opening file");
        return -1; // Exit the program with an error code
    }

    int i = 1;
    char singleLineContent[150];

    while (fgets(singleLineContent, 150, fPointer) != NULL) // Check for EOF
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
