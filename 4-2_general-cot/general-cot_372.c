#include <stdio.h>
#include <string.h>

int main() {
    int i, n, count = 1; // Initialize count to 1 assuming an empty string is a palindrome
    char f[30];

    printf("Enter the string: ");
    fgets(f, 30, stdin);
    n = strlen(f) - 1; // Exclude the newline character from length

    for (i = 0; i < n/2; i++) {
        if (f[i] != f[n-i-1]) {
            count = 0;
            break;
        }
    }

    if (count == 1) {
        printf("Entered string is Palindrome\n");
    } else {
        printf("Entered string is NOT Palindrome\n");
    }

    return 0;
}
