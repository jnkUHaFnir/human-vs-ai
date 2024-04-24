#include <stdio.h>

int main() {
    int numOfDef;
    
    while(1) {
        printf("Enter a positive integer: ");
        if(scanf("%d", &numOfDef) != 1 || numOfDef <= 0) {
            printf("Not a positive number. Please try again.\n");
            // Clear the input buffer
            int c;
            while((c = getchar()) != '\n' && c != EOF) {}
        } else {
            break;
        }
    }
    
    printf("You entered a positive integer: %d\n", numOfDef);

    return 0;
}
