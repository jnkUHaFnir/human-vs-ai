#include <stdio.h>
#include <stdlib.h>

int main() 
{ 
    char name, test, er, tr;

    printf("target: ");
    scanf("%c", &name);
    printf("target: ");
    scanf(" %c", &test);
    printf("target: ");
    scanf(" %c", &er);
    printf("target: ");
    scanf(" %c", &tr);

    printf("%c.%c.%c.%c\n", name, test, er, tr);

    char command[50];
    sprintf(command, "ping %c.%c.%c.%c", name, test, er, tr);
    system(command);
    
    return 0; 
}
