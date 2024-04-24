#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp = fopen("file.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    char string[100];
    const char fetch[] = "learning";

    while (fgets(string, 100, fp))
    {
        char *result = strstr(string, fetch);
        if (result != NULL) {
            printf("Your result is: %s", result);
            break; // Remove this line to print all occurrences in the file
        }
    }

    fclose(fp);
    return 0;
}
