#include <stdio.h>
#include <stdlib.h>

int main() {
    int myArray[240][30];
    char line[240];
    char *token;
    int i = 0, j = 0, n;
    FILE *fp;

    fp = fopen("array_list.txt", "rt");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        j = 0;
        token = strtok(line, " ");

        while (token != NULL && j < 30) {
            n = atoi(token);
            myArray[i][j] = n;
            printf("%d ", myArray[i][j]);

            token = strtok(NULL, " ");
            j++;
        }

        printf("\n");
        i++;
    }

    fclose(fp);
    return 0;
}
