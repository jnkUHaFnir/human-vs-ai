#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    char name[16]; // Assuming IPv4 address, so 15 characters for xxx.xxx.xxx.xxx format
    printf("Enter target IP address: ");
    scanf("%15s", name);
    
    // Construct the ping command string using the input IP address
    char command[50]; // Allocate enough space for the command
    snprintf(command, sizeof(command), "ping %s", name);
    
    // Execute the ping command
    system(command);
    
    return 0; 
}
