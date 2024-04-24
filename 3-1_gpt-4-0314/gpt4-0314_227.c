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

    char command[100]; // A buffer to store the formatted string
    sprintf(command, "ping %c.%c.%c.%c", name, test, er, tr); // Format the string, don't forget to remove the newline character "\n"
    system(command); // Pass the formatted command to system function

    return 0;
}
