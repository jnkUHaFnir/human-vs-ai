#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("Type the name of a file to be read (30 character max): ");
    char fileName[30];
    scanf("%29s", fileName);

    printf("Type the name of the destination file (30 character max): ");
    char fileNameW[30];
    scanf("%29s", fileNameW);

    FILE *fPointerForWriting = fopen(fileNameW, "w");
    if (fPointerForWriting == NULL) {
        printf("Error opening destination file.\n");
        return -2;
    }

    FILE *fPointer = fopen(fileName, "r");
    if (fPointer == NULL) {
        printf("Error opening file to read.\n");
        fclose(fPointerForWriting);
        return -1;
    }

    int i = 1;
    char singleLineContent[150];

    while (fgets(singleLineContent, sizeof(singleLineContent), fPointer))
    {
        char *token = strtok(singleLineContent, ",\n");
        if (token == NULL) {
            printf("Error reading tokens from line %d\n", i);
            fclose(fPointerForWriting);
            fclose(fPointer);
            return -3;
        }
        fprintf(fPointerForWriting, "%d", atoi(token));

        token = strtok(NULL, ",\n");
        if (token == NULL) {
            printf("Error reading tokens from line %d\n", i);
            fclose(fPointerForWriting);
            fclose(fPointer);
            return -3;
        }

        fprintf(fPointerForWriting, ",%d     %d\n", atoi(token), i);
        i++;
    }

    fclose(fPointerForWriting);
    fclose(fPointer);

    return 0;
}
