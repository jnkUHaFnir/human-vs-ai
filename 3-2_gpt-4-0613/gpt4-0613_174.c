#include <stdio.h>
#include <string.h>

void split_float_parts(char *str, char *sign, char *integral, char *fractional, char *exponent) {
    *sign = *str; // assign the sign

    char *dot = strchr(str, '.');
    strncpy(integral, str + 1, dot - (str + 1)); // copy the integral part 

    char *e = strchr(str, 'E');
    strncpy(fractional, dot + 1, e - (dot + 1)); // Copy the fractional part

    strcpy(exponent, e + 1); // copy the exponent
}

int main() {
    char input_str[30] = "+6.590472E-01";
    char sign, integral[10], fractional[10], exponent[10];

    split_float_parts(input_str, &sign, integral, fractional, exponent);
    printf("sign: %c, integral part: %s, fractional part: %s, exponent: %s\n", sign, integral, fractional, exponent);
    return 0;
}
