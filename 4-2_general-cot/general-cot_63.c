#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    char temp;
    char variable1[50];
    char variable2[50];

    // Reading the first input
    scanf("%c", &temp);
    clearInputBuffer();
    fgets(variable1, 50, stdin);
    strtok(variable1, "\n");

    printf("%s ", variable1);

    // Reading the second input
    if (1) {
        scanf("%c", &temp);
        clearInputBuffer();
        fgets(variable2, 50, stdin);
        strtok(variable2, "\n");

        printf("%s ", variable2);
    }

    return 0;
}
