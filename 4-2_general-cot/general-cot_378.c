#include <stdio.h>

int main() {
    int size;
    int error = 0;
    
    do {
        if (error) {
            printf("Invalid size\n");
        }
        
        printf("Size of tower (0 <= x <= 23): ");
        scanf("%i", &size);
        
        if ((size <= 23) && (size >= 0)) {
            error = 0; // Reset error flag if input is valid
        } else {
            error = 1;
        }
    } while (size > 23 || size < 0);

    return 0;
}
