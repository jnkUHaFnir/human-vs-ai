#include<stdio.h>
#include<string.h>

int main()
{
    int i, n, count = 0;
    char f[30];
    
    printf("Enter the string: ");
    fgets(f, sizeof(f), stdin);
    
    n = strlen(f);
    
    // Remove the newline character from the input
    if (f[n - 1] == '\n') {
        f[n - 1] = '\0';
        n--;
    }
    
    for (i = 0; i < n / 2; i++) {
        if (f[i] == f[n - i - 1]) {
            count += 1;
        }
    }
    
    if (count == n / 2) {
        printf("\nEntered string is Palindrome\n");
    } else {
        printf("\nEntered string is NOT Palindrome\n");
    }
    
    return 0;
}
