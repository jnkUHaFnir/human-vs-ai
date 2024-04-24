#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char input[50];
    char *token;
    double decimalPart;
    int isValid = 0;

    printf("Enter a floating number: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    // Split the input by decimal point
    token = strtok(input, ".");

    // Check if the second part exists
    if ((token = strtok(NULL, ".")) != NULL) {
        decimalPart = atof(token); // Convert decimal part to double
        if (decimalPart != 0) {
            isValid = 1;
        }
    }

    if (isValid) {
        printf("Valid floating point number entered: %s\n", input);
    } else {
        printf("Invalid floating point number entered\n");
    }

    return 0;
}
