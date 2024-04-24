#include <stdio.h>
#include <string.h>

int main() {
    int i, n, count = 0;
    char f[30];

    printf("Enter the string: ");
    gets(f);

    n = strlen(f);
    
    for (i = 0; i < n / 2; i++) {
        if (f[i] == f[n - i - 1])
            count = count + 1;
    }

    if (count == n / 2)
        printf("Entered string is Palindrome\n");
    else
        printf("Entered string is NOT Palindrome\n");

    return 0;
}
