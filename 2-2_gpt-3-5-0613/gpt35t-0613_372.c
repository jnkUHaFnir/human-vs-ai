#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isPalindrome(char* str)
{
    int i = 0;
    int j = strlen(str) - 1;

    while (i < j) {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    char str[30];
    printf("Enter the string: ");
    gets(str);

    if (isPalindrome(str))
        printf("Entered string is Palindrome\n");
    else
        printf("Entered string is not Palindrome\n");

    return 0;
}
