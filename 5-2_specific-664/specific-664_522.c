#include <stdio.h>
#include <string.h>

int main() {
    char temp;
    char variable1[50];
    char variable2[50];

    scanf("%c", &temp);
    getchar(); // Consume the newline character
    fgets(variable1, 50, stdin);
    strtok(variable1, "\n");

    printf("%s\n", variable1);

    if (1) {
        scanf("%c", &temp);
        getchar(); // Consume the newline character
        fgets(variable2, 50, stdin);
        strtok(variable2, "\n");

        printf("%s\n", variable2);
    }

    return 0;
}
