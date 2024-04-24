#include <stdio.h>
#include <string.h>

char string1[20];
char string2[20];

int main() {
    int test;

    printf("Enter 'string1'\n");
    // Use %19s to read up to 19 characters to avoid buffer overflow
    scanf("%19s", string1);

    printf("Enter 'string2'\n");
    // Use %19s to read up to 19 characters to avoid buffer overflow
    scanf("%19s", string2);

    test = strcmp(string1, string2);

    if (test > 0)
        printf("String 'string1' is greater than 'string2'\n");
    else if (test < 0)
        printf("String 'string1' is less than 'string2'\n");
    else if (test == 0)
        printf("\nString 'string1' is equal to 'string2'\n");

    printf("The value of 'test' is: %d\n", test);

    return 0;
}
