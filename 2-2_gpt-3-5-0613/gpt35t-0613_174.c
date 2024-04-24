char sign;
int digit;
int fraction;
int exponent;

fscanf(file, "%c%1d.%dE%3d;", &sign, &digit, &fraction, &exponent);
#include <stdio.h>

int main() {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Error opening the file\n");
        return 1;
    }

    char line[30];
    while (fgets(line, sizeof(line), file) != NULL) {
        char sign;
        int digit;
        int fraction;
        int exponent;
        sscanf(line, "%c%1d.%dE%3d;", &sign, &digit, &fraction, &exponent);
        printf("Sign: %c\n", sign);
        printf("Digit: %d\n", digit);
        printf("Fraction: %d\n", fraction);
        printf("Exponent: %d\n", exponent);
    }

    fclose(file);
    return 0;
}
