#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isFloat(const char* input) {
    char extra;
    double value;
    int consumed = sscanf(input, "%lf %c", &value, &extra);
    if (consumed == 1 && (isspace(extra) || extra == '\0')) {
        return 1; // Valid floating-point number
    }
    return 0; // Not a valid floating-point number
}

int main() {
    char input[50]; // Adjust the size as needed
    printf("Enter a floating point number: ");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    if (isFloat(input)) {
        printf("Valid floating point number: %s\n", input);
    } else {
        printf("Invalid floating point number.\n");
    }

    return 0;
}
