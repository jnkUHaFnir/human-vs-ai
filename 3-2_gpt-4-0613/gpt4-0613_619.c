#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    char str_name[16];  // changed from 15 to 16

    printf("Please enter your first name to begin: ");
    scanf("%15s", str_name);  // remove '_countof(str_name)', using '%15s'
    getchar();
    
    if (strlen(str_name) > 15)  // in practical, this condition should be 'if (strlen(str_name) > 14)' 
                                // as 'str_name' must save a terminating null character at the end of string.
    {
        printf("The entered name is too long, please restart the program and try again.");
        getchar();
        exit(0);
    }
    else
    {
        str_name[0] = toupper(str_name[0]);

        printf("Hi %s.\n", str_name);
        getchar();
    }
    
    return 0;
}
fgets(str_name, sizeof(str_name), stdin);
