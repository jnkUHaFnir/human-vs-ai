#include <stdio.h>
#include <stdlib.h>

int main() {
    char name, test, er, tr;
    
    printf("target: ");
    name = getchar();
    getchar(); // Consume the newline character
    
    printf("target: ");
    test = getchar();
    getchar();
    
    printf("target: ");
    er = getchar();
    getchar();
    
    printf("target: ");
    tr = getchar();
    getchar();
    
    printf("%c.%c.%c.%c\n", name, test, er, tr);
    
    char pingCommand[50]; // Allocate enough space for the command
    sprintf(pingCommand, "ping %c.%c.%c.%c", name, test, er, tr);
    
    system(pingCommand);
    
    return 0;
}
