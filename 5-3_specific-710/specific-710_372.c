#include <stdio.h>
#include <string.h>

int main()
{
    int i, n, count = 0;
    char f[30];

    printf("Enter the string: ");
    fgets(f, 30, stdin);
    
    n = strlen(f) - 1; // Exclude the newline character added by fgets

    for (i = 0; i < n/2; i++)
    {
        if (f[i] != f[n - i - 1])
        {
            count = 1;
            break;
        }
    }

    if (count == 0)
    {
        printf("\nEntered string is Palindrome\n");
    }
    else
    {
        printf("\nEntered string is NOT Palindrome\n");
    }

    return 0;
}
