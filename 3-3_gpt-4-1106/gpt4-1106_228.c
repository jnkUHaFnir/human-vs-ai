#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{ 
    // Get parts of the IP address (or the entire IP as a string)
    string ip_part1 = get_string("Enter the first part of the IP address: ");
    string ip_part2 = get_string("Enter the second part of the IP address: ");
    string ip_part3 = get_string("Enter the third part of the IP address: ");
    string ip_part4 = get_string("Enter the fourth part of the IP address: ");
    
    // Assemble the command using snprintf
    char command[256]; // Make sure this buffer is large enough
    snprintf(command, sizeof(command), "ping %s.%s.%s.%s", ip_part1, ip_part2, ip_part3, ip_part4);
    
    // Now print the command to verify it
    printf("Command to execute: %s\n", command);
    
    // Execute the command
    system(command);

    return 0; 
}
