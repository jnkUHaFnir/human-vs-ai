#include <stdio.h>

int main() {
    int size;
    
    while (1) {
        printf("Size of tower (0 <= x <= 23): ");
        scanf("%i", &size);
        
        if (size >= 0 && size <= 23) break; // If the input is valid, exit the loop
        
        printf("Invalid size\n"); // This will only be displayed if the input is invalid
    }
    
    // Continue with the rest of your program
    return 0;
}
