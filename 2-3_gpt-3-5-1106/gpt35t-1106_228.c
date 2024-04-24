#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
  
int main() 
{ 
    char name[100];
    printf("target: ");
    scanf("%s", name);

    char command[100];
    sprintf(command, "ping %s", name);
    
    printf("Pinging %s\n", name);
    system(command);
    
   return 0; 
}
