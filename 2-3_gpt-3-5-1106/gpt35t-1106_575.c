#include <stdio.h>
#include <string.h>

char string1[20];
char string2[20];

int main() {
    int test;

    printf("Enter 'string1'\n");
    fgets(string1, 20, stdin);
    printf("Enter 'string2'\n");
    fgets(string2, 20, stdin);

    test = strcmp(string1, string2);

    if (test > 0)
        printf("String 'string1' is greater than 'string2'\n");
    else if (test < 0)
        printf("String 'string1' is less than 'string2'\n");
    else if (test == 0)
        printf("\nString 'string1' is equal to 'string2'");

    printf("\nThe value of 'test' is: %d", test);

    return 0;
}
