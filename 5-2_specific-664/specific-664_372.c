#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 30

int main() {
    int i, n, count = 0;
    char f[MAX_LENGTH];
    
    printf("Enter the string: ");
    fgets(f, MAX_LENGTH, stdin);
    f[strcspn(f, "\n")] = '\0'; // remove the newline character from the input

    n = strlen(f);

    for(i = 0; i < n/2; i++) {
        if(f[i] == f[n-1-i])
            count++;
    }

    if(count == n/2)
        printf("Entered string is Palindrome\n");
    else
        printf("Entered string is NOT Palindrome\n");

    return 0;
}
