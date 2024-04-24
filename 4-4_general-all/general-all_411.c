#include <stdio.h>
#include <ctype.h>

void shift(char *my_string);

int main() {
    char inputstring[50];

    printf("Enter a string: ");
    fgets(inputstring, 50, stdin);
    shift(inputstring); 
    return 0;
}

void shift(char *my_string) {
    char ch = my_string[0]; // Get the first character of the input string

    for (int i = 0; my_string[i]; i++) {
        if (ch >= 'A' && ch <= 'Z') {
            putchar(toupper(my_string[i]));
        } else if (ch >= 'a' && ch <= 'z') {
            putchar(tolower(my_string[i]));
        }
    }
    return;
}
