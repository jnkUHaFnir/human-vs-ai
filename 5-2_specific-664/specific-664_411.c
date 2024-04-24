#include <stdio.h>
#include <ctype.h>

void shift(char *my_string);

int main() {
    char inputstring[50];

    printf("Enter a string: ");
    scanf("%49[^\n]", inputstring); // Read up to 49 characters until newline

    shift(inputstring);
    printf("\n");

    return 0;
}

void shift(char *my_string) {
    if (isupper(my_string[0])) {
        for (int i = 0; my_string[i]; i++) {
            putchar(toupper(my_string[i]));
        }
    } else if (islower(my_string[0])) {
        for (int i = 0; my_string[i]; i++) {
            putchar(tolower(my_string[i]));
        }
    }
}
