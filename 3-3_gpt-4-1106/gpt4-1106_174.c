#include <stdio.h>

int main () {
    FILE *file;
    char sign, exponent_sign;
    int before_dot, exponent;
    unsigned long after_dot;

    file = fopen("yourfile.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return(-1);
    }

    // Assuming you are reading line by line and you have isolated the number string
    while (fscanf(file, "%c%d.%6luE%c%d", &sign, &before_dot, &after_dot, &exponent_sign, &exponent) == 5) {
        // Process your data
        printf("Sign: %c\n", sign);
        printf("Before dot: %d\n", before_dot);
        printf("After dot: %06lu\n", after_dot);
        printf("Exponent sign: %c\n", exponent_sign);
        printf("Exponent: %d\n", exponent);

        // Consume until end of line or next data
        fscanf(file,"%*[;\n]");
    }

    fclose(file);
    
    return 0;
}
