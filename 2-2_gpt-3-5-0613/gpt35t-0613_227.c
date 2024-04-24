#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name = get_char("target: ");
    char test = get_char("target: ");
    char er = get_char("target: ");
    char tr = get_char("target: ");
    printf("%c.%c.%c.%c\n", name, test, er, tr);
    
    char command[50]; // Create a string to store the formatted command
    sprintf(command, "ping %c.%c.%c.%c", name, test, er, tr); // Format the command
    
    system(command); // Pass the formatted string to system
    
    return 0;
}
