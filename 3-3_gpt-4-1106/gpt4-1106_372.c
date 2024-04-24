#include<stdio.h>
#include<string.h>

int main() {
    int i, n, isPalindrome = 1;
    char f[30];

    printf("Enter the string: ");
    fgets(f, 30, stdin);  // Use fgets to prevent buffer overflow
    f[strcspn(f, "\n")] = 0;  // Remove the newline character if fgets reads it.

    n = strlen(f);

    for(i = 0; i < n / 2; i++) {
        if(f[i] != f[n - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }

    if(isPalindrome)
        printf("\nEntered string is Palindrome\n");
    else
        printf("\nEntered string is NOT Palindrome\n");

    return 0; // Should return an integer since the return type of main is int, not void.
}
