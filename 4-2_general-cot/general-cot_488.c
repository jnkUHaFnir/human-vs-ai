#include <stdio.h>

int main() {
    char sign;
    int beforeDot;
    int afterDot;
    int exponent;

    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(file, "%c%d.%dE%d;", &sign, &beforeDot, &afterDot, &exponent) == 4) {
        printf("Sign: %c, Before Dot: %d, After Dot: %d, Exponent: %d\n", sign, beforeDot, afterDot, exponent);
    }

    fclose(file);
    return 0;
}
