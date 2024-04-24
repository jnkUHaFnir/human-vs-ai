#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for isupper and islower

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    // Read a string from stdin
    fgets(cAFirst, 25, stdin);
    
    // Iterate over each character until the null terminator
    for (size_t i = 0; cAFirst[i] != '\0'; i++) {
        // Use isupper and islower to check for uppercase and lowercase
        if (isupper(cAFirst[i])) {
            uc++;
        }
        if (islower(cAFirst[i])) {
            lc++;
        }
    }

    // Print the result
    printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    return 0;
}
