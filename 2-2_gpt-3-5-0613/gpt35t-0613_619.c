#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char str_name[16];

    printf("Please enter your first name to begin: ");
    scanf("%15s", str_name);
    getchar();
    
    while (strlen(str_name) > 15)
    {
        printf("The entered name is too long. Please enter a shorter name: ");
        scanf("%15s", str_name);
        getchar();
    }
    
    str_name[0] = toupper(str_name[0]);

    printf("Hi %s.\n", str_name);
    
    return 0;
}
