#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() 
{ 
    char name, test, er, tr;
    
    printf("Enter the target IP address:\n");
    scanf("%c.%c.%c.%c", &name, &test, &er, &tr);
    
    char command[50];
    sprintf(command, "ping %c.%c.%c.%c", name, test, er, tr);
    
    system(command);
    
    return 0; 
}
