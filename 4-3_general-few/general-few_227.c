#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    char name, test, er, tr;
    
    printf("Enter target IP address (format: 'x.y.z.w'): ");
    scanf("%c.%c.%c.%c", &name, &test, &er, &tr);
    
    char command[50]; // Assuming IP address won't exceed 50 characters
    
    sprintf(command, "ping %c.%c.%c.%c", name, test, er, tr);
    
    printf("Executing command: %s\n", command);
    
    system(command);
    
    return 0; 
}
