#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char str_name[20]; // increase the size of the array to accommodate longer names

    printf("Please enter your first name to begin: ");
    scanf_s("%19s", str_name, _countof(str_name)); // adjust the size in the scanf_s function
    getchar();
    
    if (strlen(str_name) > 15)
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
