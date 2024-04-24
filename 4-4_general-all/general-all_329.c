#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    printf("Type the name of a file to be read (30 character max): ");
    char fileName[30];
    scanf("%s", fileName);

    printf("Type the name of destination file (30 character max): ");
    char fileNameW[30];
    scanf("%s", fileNameW);

    FILE *fPointerForWriting = fopen(fileNameW, "w");
    FILE *fPointer = fopen(fileName, "r");

    if (fPointer == NULL || fPointerForWriting == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    char *singleLineContent = NULL;
    size_t len = 0;
    
    int i = 1;
    while (getline(&singleLineContent, &len, fPointer) != -1) {
        char *token = strtok(singleLineContent, ",\n");
        
        if (token != NULL) {
            fprintf(fPointerForWriting, "%d", atoi(token));
            token = strtok(NULL, ",\n");

            if (token != NULL) {
                fprintf(fPointerForWriting, ",%d     %d\n", atoi(token), i);
            } else {
                printf("Incomplete line\n");
            }
        }

        i++;
    }

    free(singleLineContent); // Free dynamically allocated memory
    fclose(fPointerForWriting);
    fclose(fPointer);

    return 0;
}
