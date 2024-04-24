#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    printf("Type the name of a file to be read (30 character max): ");
    char fileName[30];
    scanf("%29s", fileName); // Limit input to prevent buffer overflow
    printf("Type the name of destination file (30 character max): ");
    char fileNameW[30];
    scanf("%29s", fileNameW); // Limit input to prevent buffer overflow

    FILE *fPointerForWriting = fopen(fileNameW, "w");
    FILE *fPointer = fopen(fileName, "r");

    if (fPointer == NULL || fPointerForWriting == NULL) {
        fprintf(stderr, "Error opening file\n");
        return -1;
    }

    int i = 1;
    char singleLineContent[256]; // Increased buffer size

    while (fgets(singleLineContent, sizeof(singleLineContent), fPointer))
    {
        char *token = strtok(singleLineContent, ",\n");
        if (token != NULL) {
            fprintf(fPointerForWriting, "%d", atoi(token));
            token = strtok(NULL, ",\n");
            if (token != NULL) {
                fprintf(fPointerForWriting, ",%d %d\n", atoi(token), i);
                i++;
            } else {
                printf("Missing data in line\n");
            }
        } else {
            printf("Empty line\n");
        }
    }

    fclose(fPointerForWriting);
    fclose(fPointer);

    return 0;
}
