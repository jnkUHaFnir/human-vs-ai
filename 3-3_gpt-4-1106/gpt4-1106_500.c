#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_uppercase(char* str) {
    while (*str) {
        putchar(toupper((unsigned char)*str));
        str++;
    }
}

int main() {
    char input1[255];
    char input2[255];
    // I assume you get title and author from somewhere else so skipping that.

    // Your code to get input1 and input2
    fgets(input1, 254, stdin);
    fgets(input2, 254, stdin);
    input1[strcspn(input1, "\n")] = '\0';
    input2[strcspn(input2, "\n")] = '\0';

    // Print in uppercase
    printf("<");
    print_uppercase(input1);
    printf("> <");
    print_uppercase(input2);
    printf(">\n");

    return 0;
}
