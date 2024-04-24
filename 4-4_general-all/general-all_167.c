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
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        j = 0;
        token = strtok(line, " ");

        while (token != NULL) {
            int n = atoi(token);
            myArray[i][j] = n;
            printf("%d ", myArray[i][j]);

            token = strtok(NULL, " "); // Move to the next token within the same line
            j++;
        }

        printf("\n");
        i++;
    }

    fclose(fp);

    return 0;
}
