#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned char n[3];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;

    char str[100]; // Assuming a maximum of 100 digits
    char *res;
    int i;
    size_t len = sizeof(n) / sizeof(n[0]);
    int num = 0;

    // Convert each digit to a string representation
    for (i = 0; i < len; i++) {
        sprintf(str + strlen(str), "%d", n[i]);
    }

    // Convert the concatenated string to an integer
    num = strtol(str, &res, 10);

    // Print the number in base 10
    printf("%d\n", num);

    return 0;
}
123
