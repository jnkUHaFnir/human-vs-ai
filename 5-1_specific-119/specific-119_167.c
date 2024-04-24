#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int myArray[240][30];
    char line[240];
    char *token;
    int i = 0, j;

    FILE *fp = fopen("array_list.txt", "rt");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        j = 0; // Reset column index for each new line
        token = strtok(line, " \t\r\n"); // Tokenize the line

        while (token != NULL && j < 30) {
            myArray[i][j] = atoi(token);
            printf("%d ", myArray[i][j]);
            j++;
            token = strtok(NULL, " \t\r\n"); // Move to next token
        }

        printf("\n");
        i++;
    }

    fclose(fp);
    return 0;
}
