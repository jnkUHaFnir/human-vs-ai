#include <stdio.h>
#include <string.h>

int main() {
    int i, n, count = 1; // Initialized count to 1 for an empty string
    char f[30];
    
    printf("Enter the string: ");
    fgets(f, 30, stdin);
    f[strcspn(f, "\n")] = '\0'; // Remove newline character if present

    n = strlen(f);

    for (i = 0; i < n / 2; i++) { // Loop until halfway through the string
        if (f[i] != f[n - i - 1]) { // Compare characters from start and end
            count = 0;
            break;
        }
    }

    if (count == 1)
        printf("\nEntered string is Palindrome\n");
    else
        printf("\nEntered string is NOT Palindrome\n");

    return 0;
}
