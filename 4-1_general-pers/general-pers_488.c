#include <stdio.h>

int main() {
    char line[30];
    char sign;
    int mantissa_int;
    int decimal_part;
    int exponent;

    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Assuming each line has the format described - repeat this for each line in the file
    while (fgets(line, sizeof(line), file) != NULL) {
        // Using the format specifier "%c%d.%dE%d;%*[+-]%d.%dE%d;"
        int result = sscanf(line, "%c%d.%dE%d;%*[+-]%d.%dE%d;", &sign, &mantissa_int, &decimal_part, &exponent, &mantissa_int, &decimal_part, &exponent);

        if (result == 7) {
            printf("Sign: %c\n", sign);
            printf("Mantissa: %d.%d\n", mantissa_int, decimal_part);
            printf("Exponent: %d\n", exponent);
        } else {
            printf("Error reading the line\n");
        }
    }

    fclose(file);
    return 0;
}
