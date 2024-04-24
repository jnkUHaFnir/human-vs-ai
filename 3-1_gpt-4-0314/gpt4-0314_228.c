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

    // Create a buffer to store the command string
    char command[50];

    // Write the command to the buffer using sprintf
    sprintf(command, "ping %c.%c.%c.%c", name, test, er, tr);

    // Execute the command string using system()
    system(command);

    return 0;
}
