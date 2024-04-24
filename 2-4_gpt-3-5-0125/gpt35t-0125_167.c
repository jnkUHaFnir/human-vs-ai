#include <stdio.h>
#include <stdlib.h>

int main() {
    int myArray[240][30];
    char line[240];
    char *token;
    int i = 0, j = 0, n;
    FILE *fp;

    fp = fopen("array_list.txt", "rt");

    while (fgets(line, sizeof(line), fp)) {
        j = 0;
        token = strtok(line, " ");

        while (token != NULL) {
            n = atoi(token);
            myArray[i][j++] = n;
            token = strtok(NULL, " ");
        }

        for (int k = 0; k < j; k++) {
            printf("%d ", myArray[i][k]);
        }
        printf("\n");
        i++;
    }

    fclose(fp);
    return 0;
}
