"%c%1d.%6[0-9E+-]%3[E]"
#include <stdio.h>

int main() {
    char line[30];
    char sign;
    int num_before_dot;
    char num_and_exp[7];  // 6 digits for number and 1 for exponent
    char exponent[4];     // 3 digits for exponent
    FILE* file = fopen("data.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fscanf(file, "%30[^\n]\n", line) == 1) {
        if (sscanf(line, "%c%1d.%6[0-9E+-]%3s\n", &sign, &num_before_dot, num_and_exp, exponent) == 4) {
            printf("Sign: %c\n", sign);
            printf("Number before dot: %d\n", num_before_dot);
            printf("Numbers and exponent: %s\n", num_and_exp);
            printf("Exponent: %s\n", exponent);
        } else {
            printf("Invalid format\n");
        }
    }

    fclose(file);
    return 0;
}
