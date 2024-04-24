#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for isupper() and islower() functions

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst, 25, stdin);

    for (size_t i = 0; i < strlen(cAFirst); i++) { // Use strlen(cAFirst) to get the actual length of the string.
        if (isupper(cAFirst[i])) { // isupper checks if the character is an uppercase letter
            uc++;
        }
        if (islower(cAFirst[i])) { // islower checks if the character is a lowercase letter
            lc++;
        }
    }

    printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    return 0;
}
