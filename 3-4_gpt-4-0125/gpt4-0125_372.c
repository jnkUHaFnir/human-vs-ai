#include<stdio.h>
#include<string.h>
void main()
{
    int i,n, isPalindrome=1; // Use a flag to denote palindrome status
    char f[30];
    printf("Enter the string: ");
    gets(f); // Note: gets() is unsafe and should be avoided. Consider using fgets() instead.
    n = strlen(f);

    for(i=0; i<n/2; i++)
    {
        if(f[i]!=f[n-i-1])
        {
            isPalindrome = 0; // Set as false if characters don't match
            break; // No need to check further if a mismatch is found
        }
    }
    if(isPalindrome)
        printf("\nEntered string is Palindrome");
    else
        printf("\nEntered string is NOT Palindrome");
}
fgets(f, sizeof(f), stdin);
size_t len = strlen(f);
if (len > 0 && f[len-1] == '\n') {
  f[len-1] = '\0'; // Remove newline character
}
n = strlen(f); // Get the "corrected" length
