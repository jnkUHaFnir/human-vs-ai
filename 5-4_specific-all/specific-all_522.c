#include <stdio.h>
#include <string.h>

int main() {
    char temp;

    // Read a single character and consume the newline character
    scanf(" %c", &temp); // Note the space before `%c`
    while ((getchar()) != '\n'); // Consume newline character

    char variable1[51]; // Including space for null terminator
    char variable2[51]; // Including space for null terminator

    printf("Enter string 1: ");
    fgets(variable1, sizeof(variable1), stdin);
    strtok(variable1, "\n");

    printf("String 1: %s\n", variable1);

    printf("Enter string 2: ");
    scanf(" %c", &temp); // Read a single character and consume the newline
    while ((getchar()) != '\n'); // Consume newline character
    fgets(variable2, sizeof(variable2), stdin);
    strtok(variable2, "\n");

    printf("String 2: %s\n", variable2);

    return 0;
}
