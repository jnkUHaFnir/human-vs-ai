#include <stdio.h>
#include <ctype.h>

void shift(char *my_string);

int main()
{
    char inputstring[50];
    
    printf("Enter a string: ");
    fgets(inputstring, sizeof(inputstring), stdin);
  
    shift(inputstring);
  
    return 0;
}

void shift (char *my_string)
{
    char first_char = my_string[0];
    int i = 1;
    
    if (islower(first_char)) {
        printf("%c", toupper(first_char));
    } else if (isupper(first_char)) {
        printf("%c", tolower(first_char));
    }
    
    while(my_string[i] != '\0')
    {
        if (isupper(first_char)) {
            printf("%c", toupper(my_string[i]));
        } else {
            printf("%c", tolower(my_string[i]));
        }
        i++;
    }
}
