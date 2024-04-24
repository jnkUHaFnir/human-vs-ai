#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    char name, test, er, tr;
    
    printf("Enter the target IP address (format: x.x.x.x): ");
    scanf("%c.%c.%c.%c", &name, &test, &er, &tr);

    char command[50];
    snprintf(command, sizeof(command), "ping %c.%c.%c.%c", name, test, er, tr);
    
    printf("Pinging target: %c.%c.%c.%c\n", name, test, er, tr);
    system(command);
    
    return 0; 
}
