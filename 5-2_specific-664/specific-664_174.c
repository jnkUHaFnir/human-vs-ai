char sign;
int integerPart;
int decimalPart;
int exponent;
fscanf(filePointer, "%c%d.%dE%d;", &sign, &integerPart, &decimalPart, &exponent);
#include <stdio.h>

int main() {
    FILE *filePointer;
    char line[30];
    char sign;
    int integerPart;
    int decimalPart;
    int exponent;

    filePointer = fopen("your_file.txt", "r");
    if (filePointer == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(filePointer, "%[^\n]\n", line) == 1) {
        sscanf(line, "%c%d.%dE%d;", &sign, &integerPart, &decimalPart, &exponent);
        // Use the extracted values as needed
        printf("Sign: %c, Integer Part: %d, Decimal Part: %d, Exponent: %d\n", sign, integerPart, decimalPart, exponent);
    }

    fclose(filePointer);
    return 0;
}
