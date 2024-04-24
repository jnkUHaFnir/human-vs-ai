#include <stdio.h>
#include <ctype.h>
#include <string.h>

void shift(char *my_string);

int main() {
    char inputstring[50];

    printf("Enter a string: ");
    fgets(inputstring, sizeof(inputstring), stdin);
    
    shift(inputstring);
    
    return 0;
}

void shift(char *my_string) {
    char first_char = my_string[0];
    
    if(first_char >= 'A' && first_char <= 'Z') { // When first char is uppercase
        for(int i = 0; my_string[i]; i++) {
            putchar(toupper(my_string[i]));
        }
    } else if(first_char >= 'a' && first_char <= 'z') { // When first char is lowercase
        for(int i = 0; my_string[i]; i++) {
            putchar(tolower(my_string[i]));
        }
    } else {
        printf("Invalid input\n");
    }
}
