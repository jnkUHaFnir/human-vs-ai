#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("Type the name of a file to be read (30 character max): ");
    char fileName[30];
    scanf("%29s", fileName); // Limit input to 29 characters to avoid buffer overflow
    printf("Type the name of the destination file (30 character max): ");
    char fileNameW[30];
    scanf("%29s", fileNameW); // Limit input to 29 characters to avoid buffer overflow

    FILE *fPointerForWriting = fopen(fileNameW, "w");
    FILE *fPointer = fopen(fileName, "r");

    int i = 1;
    char *singleLineContent = NULL;
    size_t bufferSize = 0;

    while(getline(&singleLineContent, &bufferSize, fPointer) != -1)
    {
        char *token = strtok(singleLineContent, ",\n");
        fprintf(fPointerForWriting, "%d", atoi(token));
        token = strtok(NULL, ",\n");
        fprintf(fPointerForWriting, ",%d     %d\n", atoi(token), i);
        if(token == NULL)
        {
            printf("There are no tokens\n");
            free(singleLineContent);
            fclose(fPointerForWriting);
            fclose(fPointer);
            return -3;
        }
        i++;
    }

    free(singleLineContent);
    fclose(fPointerForWriting);
    fclose(fPointer);

    return 0;
}
