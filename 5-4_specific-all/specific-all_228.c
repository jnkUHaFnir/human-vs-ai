#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    char name[16];
    char test[16];
    char er[16];
    char tr[16];
    
    printf("Enter the IP address for ping:\n");
    scanf("%s.%s.%s.%s", name, test, er, tr);
    
    char command[64];
    snprintf(command, sizeof(command), "ping %s.%s.%s.%s", name, test, er, tr);
    
    printf("Executing command: %s\n", command);
    system(command);
    
    return 0; 
}
