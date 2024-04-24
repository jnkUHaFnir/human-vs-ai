#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    printf("Enter a number: ");
    
    if (scanf("%d", &num) == 1) {
        printf("The input is a number.\n");
    } else {
        printf("The input is not a number.\n");
        // Clear input buffer
        while (getchar() != '\n');
    }

    return 0;
}
