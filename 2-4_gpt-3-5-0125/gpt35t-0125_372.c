#include<stdio.h>
#include<string.h>

int main()
{
    int i, n, count = 1;
    char f[30];
    
    printf("Enter the string: ");
    gets(f);
    
    n = strlen(f);

    for(i=0; i<n/2; i++)
    {
        if(f[i] != f[n-i-1])
        {
            count = 0;
            break;
        }
    }

    if(count == 1)
    {
        printf("\nEntered string is Palindrome");
    }
    else
    {
        printf("\nEntered string is NOT Palindrome");
    }

    return 0;
}
