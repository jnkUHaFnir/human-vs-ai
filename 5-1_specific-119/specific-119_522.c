#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to flush the input buffer
void flushInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    char temp;
    char variable1[50], variable2[50];

    // Get input for variable1
    printf("Enter input for variable1: ");
    scanf(" %c", &temp);
    flushInputBuffer(); // Flush the input buffer
    fgets(variable1, 50, stdin);
    strtok(variable1, "\n");

    printf("Variable1: %s\n", variable1);

    // Get input for variable2
    if (1) {
        printf("Enter input for variable2: ");
        scanf(" %c", &temp);
        flushInputBuffer(); // Flush the input buffer
        fgets(variable2, 50, stdin);
        strtok(variable2, "\n");

        printf("Variable2: %s\n", variable2);
    }

    return 0;
}
