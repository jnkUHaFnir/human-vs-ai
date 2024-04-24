#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> 

int main() 
{ 
    // Assuming that you are trying to get individual octets of an IP address as characters
    // If not, you may have to use `get_string` or another suitable function for input
    char name = get_char("target first octet: ");
    char test = get_char("target second octet: ");
    char er = get_char("target third octet: ");
    char tr = get_char("target fourth octet: ");
    printf("%c.%c.%c.%c\n", name, test, er, tr);

    // Create a buffer to hold the ping command
    char command[256]; // You can adjust the size as necessary

    // Format the ping command and store in 'command' buffer
    sprintf(command, "ping %c.%c.%c.%c", name, test, er, tr);

    // Execute the command using system
    system(command);

    return 0; 
}
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> 

int main() 
{ 
    string ip_address = get_string("Target IP address: ");
    printf("%s\n", ip_address);

    // Create a buffer to hold the ping command with enough space for the command, IP address, and null terminator
    char command[256]; // You can adjust the size as necessary

    // Safely format the ping command and store in 'command' buffer with a maximum length - this prevents buffer overflow
    snprintf(command, sizeof(command), "ping %s", ip_address);

    // Execute the command using system
    system(command);

    return 0; 
}
