#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    char name = get_char("target: ");
    char test = get_char("target: ");
    char er = get_char("target: ");
    char tr = get_char("target: ");
    
    char pingCommand[100]; // Allocate enough space for the ping command
    sprintf(pingCommand, "ping %c.%c.%c.%c", name, test, er, tr);
    
    printf("%c.%c.%c.%c\n", name, test, er, tr);
    system(pingCommand);
    
    return 0; 
}
