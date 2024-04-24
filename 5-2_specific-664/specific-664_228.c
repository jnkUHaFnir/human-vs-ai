#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    char name[100];
    printf("Enter the target IP address:\n");
    scanf("%s", name);

    char command[100];
    sprintf(command, "ping %s", name);

    system(command);

    return 0; 
}
