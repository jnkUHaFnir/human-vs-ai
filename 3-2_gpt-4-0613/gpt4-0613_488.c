#include <stdio.h>
#include <stdlib.h>

int main()
{
    char line[30] = "+6.590472E-01";
    int sign = 0;
    unsigned long numberBeforeDot = 0;
    unsigned long numberAfterDot = 0;
    int exponent = 0;

    /* Pre-processing the line to separate important parts */
    for (char *ptr = line; *ptr; ++ptr) {
        /* Convert 'E' and dot to space, so sscanf can easily separate parts */
        if (*ptr == 'E' || *ptr == '.')
            *ptr = ' ';
    }

    /* Now, sscanf can parse the line */
    sscanf(line, "%d %lu %lu %d", &sign, &numberBeforeDot, &numberAfterDot, &exponent);

    printf("Sign: %d\n", sign);
    printf("Number before dot: %lu\n", numberBeforeDot);
    printf("Number after dot: %lu\n", numberAfterDot);
    printf("Exponent: %d\n", exponent);

    return 0;
}
