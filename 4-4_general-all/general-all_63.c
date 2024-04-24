#include <stdio.h>
#include <string.h>

int main() {
    char temp;
    char variable1[50];
    char variable2[50];

    printf("Enter string 1: ");
    scanf(" %c", &temp); // Notice the space before %c to consume any leading whitespace
    fgets(variable1, 50, stdin);
    strtok(variable1, "\n");

    printf("%s\n", variable1);

    // Clear the input buffer before reading the next input
    while ((temp = getchar()) != '\n' && temp != EOF) {}

    if (1) {
        printf("Enter string 2: ");
        scanf(" %c", &temp);
        fgets(variable2, 50, stdin);
        strtok(variable2, "\n");

        printf("%s\n", variable2);
    }

    return 0;
}
