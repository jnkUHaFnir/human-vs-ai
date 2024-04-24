#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) == 1) {
        printf("Valid number.\n");
    } else {
        printf("Invalid input.\n");
    }
    return 0;
}
