#include <stdio.h>

int main() {
    char line[30];
    char sign;
    int beforeDot;
    int afterDot;
    int exponent;

    FILE *file = fopen("your_file.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%*[^\n]\n%*[^\n]\n%1c%1d.%6dE%3d;%*[^\n]\n", &sign, &beforeDot, &afterDot, &exponent) == 4) {
        printf("Sign: %c\n", sign);
        printf("Before Dot: %d\n", beforeDot);
        printf("After Dot: %d\n", afterDot);
        printf("Exponent: %d\n", exponent);
    }

    fclose(file);
    return 0;
}
