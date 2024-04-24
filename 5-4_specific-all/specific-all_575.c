#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 20

char string1[MAX_LENGTH];
char string2[MAX_LENGTH];

int main() {
    int test;

    printf("Enter 'string1': ");
    fgets(string1, MAX_LENGTH, stdin);
    string1[strcspn(string1, "\n")] = 0; // Remove the newline character

    printf("Enter 'string2': ");
    fgets(string2, MAX_LENGTH, stdin);
    string2[strcspn(string2, "\n")] = 0; // Remove the newline character

    test = strcmp(string1, string2);

    if (test < 0) {
        printf("String 'string1' is less than 'string2'\n");
    } else if (test > 0) {
        printf("String 'string1' is greater than 'string2'\n");
    } else {
        printf("String 'string1' is equal to 'string2'\n");
    }

    printf("The value of 'test' is: %d\n", test);

    return 0;
}
