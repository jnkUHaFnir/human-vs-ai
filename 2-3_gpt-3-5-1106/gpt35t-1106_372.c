#include<stdio.h>
#include<string.h>

int main()
{
    int i, n, count = 0;
    char f[30];

    printf("Enter the string: ");
    scanf("%s", f);
    n = strlen(f);

    for (i = 0; i < n/2; i++) {
        if (f[i] != f[n - i - 1]) {
            count = 1;
            break;
        }
    }

    if (count == 0) {
        printf("Entered string is a palindrome.\n");
    } else {
        printf("Entered string is NOT a palindrome.\n");
    }

    return 0;
}
