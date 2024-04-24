#include <stdio.h>
#include <string.h>

void construct_string(char *result, const char *prefix, int number, const char *suffix)
{
    sprintf(result, "%s%03d%s", prefix, number, suffix);
}

int main()
{
    char string4H1[10] = "*FV";
    char string4H3[10] = "*RV";
    char string4H2[10] = "#";

    int num1 = 200; // Replace these values with the actual numbers fetched from memory
    int num2 = 200;

    char result1[10];
    char result2[10];

    construct_string(result1, string4H1, num1, string4H2); // Constructs "*FV200#"
    construct_string(result2, string4H3, num2, string4H2); // Constructs "*RV200#"

    printf("%s\n", result1); // Display result1
    printf("%s\n", result2); // Display result2

    return 0;
}
