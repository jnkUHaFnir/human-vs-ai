#include <stdio.h>

int main() {
    
    char address[1000]; // assuming the maximum length is 1000
    
    printf("Enter the employee's address: ");
    fgets(address, sizeof(address), stdin);
    
    printf("\nThe employee's address is: %s", address);
    
    return 0;
}
