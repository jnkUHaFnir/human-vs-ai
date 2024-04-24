#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    char target[256]; // Assuming no hostname or IP address will exceed this length
    printf("Enter target: ");
    // No need for cs50.h library, just use scanf to get a string
    scanf("%255s", target); // %255s to prevent buffer overflows
    char command[300]; // Buffer to hold the command string
    sprintf(command, "ping %s", target); //Building the command string
    system(command); // Execute the shell command
    
    return 0; 
}
