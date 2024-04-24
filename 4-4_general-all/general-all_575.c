#include <stdio.h>
#include <string.h>

char string1[20];
char string2[20];

int main() {
    int test;

    printf("Enter 'string1'\n");
    scanf("%19s", string1); // Use %19s to limit input to 19 characters to avoid buffer overflow
    printf("Enter 'string2'\n");
    scanf("%19s", string2); // Use %19s to limit input to 19 characters to avoid buffer overflow

    test = strcmp(string1, string2);

    if (test > 0)
        printf("String 'string1' is greater than 'string2'\n");
    else if (test < 0)
        printf("String 'string1' is less than 'string2'\n");
    else if (test == 0)
        printf("String 'string1' is equal to 'string2'\n");

    printf("The value of 'test' is: %d\n", test);

    return 0;
}
