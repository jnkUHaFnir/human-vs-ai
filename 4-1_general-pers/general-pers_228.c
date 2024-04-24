#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    char name, test, er, tr;
    
    printf("Enter the target IP address: ");
    scanf("%c.%c.%c.%c", &name, &test, &er, &tr);

    char command[50];
    sprintf(command, "ping %c.%c.%c.%c", name, test, er, tr);
    
    printf("Pinging %s\n", command);
    system(command);
    
    return 0; 
}
