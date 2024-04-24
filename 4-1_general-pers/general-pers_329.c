#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILE_NAME_LENGTH 30
#define MAX_LINE_LENGTH 256

int main()
{
    char fileName[MAX_FILE_NAME_LENGTH + 1];
    char fileNameW[MAX_FILE_NAME_LENGTH + 1];

    printf("Type the name of a file to be read (max %d characters): ", MAX_FILE_NAME_LENGTH);
    scanf("%29s", fileName);
    
    printf("Type the name of destination file (max %d characters): ", MAX_FILE_NAME_LENGTH);
    scanf("%29s", fileNameW);

    FILE *fPointerForWriting = fopen(fileNameW, "w");
    FILE *fPointer = fopen(fileName, "r");

    if (fPointer == NULL || fPointerForWriting == NULL) {
        printf("Error opening files!\n");
        return -1;
    }

    int i = 1;
    char singleLineContent[MAX_LINE_LENGTH];

    while (fgets(singleLineContent, sizeof(singleLineContent), fPointer))
    {
        char *token = strtok(singleLineContent, ",\n");
        
        if (token == NULL) {
            printf("Error: No tokens found in line %d\n", i);
            break;
        }
        
        fprintf(fPointerForWriting, "%d", atoi(token));

        token = strtok(NULL, ",\n");

        if (token == NULL) {
            printf("Error: Incomplete data in line %d\n", i);
            break;
        }

        fprintf(fPointerForWriting, ",%d     %d\n", atoi(token), i);
        
        i++;
    }

    fclose(fPointerForWriting);
    fclose(fPointer);

    return 0;
}
