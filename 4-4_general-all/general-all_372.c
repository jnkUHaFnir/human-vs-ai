#include <stdio.h>
#include <string.h>

int main()
{
    int i, n, count = 0;
    char f[30];
    
    printf("Enter the string: ");
    fgets(f, sizeof(f), stdin); // Use fgets instead of gets to prevent buffer overflow

    n = strlen(f);
    
    // Remove newline character if present at the end of the input
    if (f[n - 1] == '\n') {
        f[n - 1] = '\0';
        n = n - 1;
    }

    for (i = 0; i < n/2; i++) {
        if (f[i] == f[n - i - 1])
            count = count + 1;
    }
    
    if (count == n/2)
        printf("\nEntered string is Palindrome\n");
    else
        printf("\nEntered string is NOT Palindrome\n");

    return 0;
}
