#include <stdio.h>
#include <ctype.h>

void shift(char *my_string); // Function declaration

int main() {
    char inputstring[50];
  
    printf("Enter a string:\n");
    if(fgets(inputstring, sizeof(inputstring), stdin)){ // Ensure fgets read successfully
        shift(inputstring); // Process the input
    }
  
    return 0;
}

void shift(char *my_string) // Function definition
{
    int i = 0;
    int toUpper = isupper(my_string[0]); // Check case of the first character
  
    while(my_string[i]) {
        // Based on the case of the first character, convert and output the whole string
        if (toUpper)
            putchar(toupper(my_string[i]));
        else
            putchar(tolower(my_string[i]));
        i++;
    }
}
