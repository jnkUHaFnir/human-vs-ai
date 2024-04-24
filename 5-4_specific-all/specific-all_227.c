#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    char ip_address[16]; // Assuming IPv4 format XXX.XXX.XXX.XXX, total of 15 characters
    printf("Enter target IP address: ");
    scanf("%15s", ip_address); // Read IP address input from user

    // Construct the full ping command as a single string
    char ping_command[50]; // Assuming command length won't exceed 50 characters
    snprintf(ping_command, sizeof(ping_command), "ping %s", ip_address);

    // Call system() with the constructed ping command string
    int result = system(ping_command);

    return 0; 
}
