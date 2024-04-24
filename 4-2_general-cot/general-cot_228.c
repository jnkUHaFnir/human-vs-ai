#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    char name[20]; // Using an array to store the IP address
    char test[20];
    char er[20];
    char tr[20];

    printf("target: ");
    scanf("%s", name);
    printf("target: ");
    scanf("%s", test);
    printf("target: ");
    scanf("%s", er);
    printf("target: ");
    scanf("%s", tr);

    printf("%s.%s.%s.%s\n", name, test, er, tr);

    // Construct the ping command with the IP address
    char command[100];
    snprintf(command, sizeof(command), "ping %s.%s.%s.%s", name, test, er, tr);
    
    // Execute the ping command
    system(command);
    
    return 0; 
}
