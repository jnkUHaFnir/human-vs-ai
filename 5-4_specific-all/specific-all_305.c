#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    
    if (scanf("%d", &num) == 1) {
        printf("You entered a number: %d\n", num);
    } else {
        printf("Input is not a number or reading failed.\n");
    }

    return 0;
}
