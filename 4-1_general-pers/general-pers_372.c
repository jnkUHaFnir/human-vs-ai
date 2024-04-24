#include <stdio.h>
#include <string.h>

int main() {
    char str[30];
    printf("Enter the string: ");
    fgets(str, sizeof(str), stdin);

    int len = strlen(str);
    int palindrome = 1; // Assume palindrome initially

    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            palindrome = 0; // Not a palindrome
            break;
        }
    }

    if (palindrome) {
        printf("Entered string is Palindrome\n");
    } else {
        printf("Entered string is NOT Palindrome\n");
    }

    return 0;
}
