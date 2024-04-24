#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *address = NULL;
    char buffer[100];
    char *temp = NULL;
    int len = 0;
    
    printf("Enter the address of the employee (press enter twice to finish):\n");
    
    while (fgets(buffer, 100, stdin) != NULL) {
        if (strcmp(buffer, "\n") == 0) {
            break;
        }
        
        len += strlen(buffer);
        temp = realloc(address, len);
        
        if (temp == NULL) {
            printf("Error allocating memory");
            exit(1);
        }
        
        address = temp;
        
        strcat(address, buffer);
    }
    
    printf("Employee address: %s", address);
    
    free(address);
    
    return 0;
}
