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

    int i = 1;
    char singleLineContent[150];

    while (fgets(singleLineContent, 150, fPointer))
    {
        char *token = strtok(singleLineContent, ",\n");
        if (token == NULL)
        {
            printf("There are no tokens\n");
            return -3;
        }
        fprintf(fPointerForWriting, "%d", atoi(token));

        token = strtok(NULL, ",\n");
        if (token == NULL)
        {
            printf("There are no tokens\n");
            return -3;
        }
        if (token[strlen(token) - 1] == '\n')
        {
            token[strlen(token) - 1] = '\0'; // Remove newline character
        }
        fprintf(fPointerForWriting, ",%d     %d\n", atoi(token), i);

        i++;
    }

    fclose(fPointerForWriting);
    fclose(fPointer);

    return 0;
}
