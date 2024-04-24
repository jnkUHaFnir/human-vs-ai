#include <stdio.h>
#include <string.h>

char string1[20] = "";
char string2[20] = "";

int main() {
    int test;

    printf("Enter 'string1':\n");
    fgets(string1, sizeof(string1), stdin);
    printf("Enter 'string2':\n");
    fgets(string2, sizeof(string2), stdin);

    // Removing newline characters that might be present in the strings
    string1[strcspn(string1, "\n")] = 0;
    string2[strcspn(string2, "\n")] = 0;

    test = strcmp(string1, string2);

    if (test > 0)
        printf("String 'string1' is greater than 'string2'\n");
    else if (test < 0)
        printf("String 'string1' is less than 'string2'\n");
    else if (test == 0)
        printf("\nString 'string1' is equal to 'string2'\n");

    printf("The value of 'test' is : %d\n", test);

    return 0;
}
