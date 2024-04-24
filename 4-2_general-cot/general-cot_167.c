#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 240
#define MAX_COLS 30

int main() {
    int myArray[MAX_ROWS][MAX_COLS];
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *token;
    int i = 0, j = 0, n;
    FILE *fp;

    fp = fopen("array_list.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        token = strtok(line, " ");

        j = 0;
        while (token != NULL && j < MAX_COLS) {
            n = atoi(token);
            myArray[i][j] = n;
            printf("%d ", myArray[i][j]);
            token = strtok(NULL, " ");
            j++;
        }

        printf("\n");
        i++;
    }

    free(line);
    fclose(fp);
    return 0;
}
