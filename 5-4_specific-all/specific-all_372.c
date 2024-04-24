#include <stdio.h>
#include <string.h>

int main() {
    int i, n, count = 0;
    char f[30];
    
    printf("Enter the string: ");
    fgets(f, 30, stdin);
    
    n = strlen(f) - 1; // excluding the newline character from fgets()
    
    for (i = 0; i < n/2; i++) {
        if (f[i] != f[n-1-i]) {
            count = 1;
            break;
        }
    }
    
    if (count == 0) {
        printf("\nEntered string is a palindrome.\n");
    } else {
        printf("\nEntered string is NOT a palindrome.\n");
    }

    return 0;
}
