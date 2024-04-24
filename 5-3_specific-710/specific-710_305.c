#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    
    if (scanf("%d", &num) == 1) {
        // Input is a valid number
        printf("Input is a number\n");
    } else {
        // Input is not a valid number
        printf("Input is not a number\n");
    }

    return 0;
}
