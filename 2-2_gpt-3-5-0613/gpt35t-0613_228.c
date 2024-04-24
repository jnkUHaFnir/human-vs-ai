#include <cs50.h>
#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    char name = get_char("target: ");
    char test = get_char("target: ");
    char er = get_char("target: ");
    char tr = get_char("target: ");
  
    // Format the ping command as a string using sprintf
    char ping_command[100];
    sprintf(ping_command, "ping %c.%c.%c.%c", name, test, er, tr);
  
    // Pass the ping command string to system()
    system(ping_command);
    
   return 0; 
}
