#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    char name[20];
    char test[20];
    char er[20];
    char tr[20];
    
    printf("Enter target: ");
    scanf("%s %s %s %s", name, test, er, tr);
    
    char command[100];
    sprintf(command, "ping %s.%s.%s.%s", name, test, er, tr);
    
    printf("Ping command: %s\n", command);
    
    system(command);
    
    return 0; 
}

Then run the executable and input the desired IP address to ping.
