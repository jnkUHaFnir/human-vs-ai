#include <stdio.h>
#include <ctype.h>

int main() {
    int num; 
    printf("Enter an integer: ");
    if (scanf("%d", &num)) { // check if scanf successfully reads an integer
        printf("You entered a number.\n");
    } else {
        printf("You did not enter a number.\n");
    }
    return 0; 
}
