#include <stdio.h>
#include <string.h>
#include <ctype.h>  // Include ctype.h for isupper and islower functions

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst, 25, stdin);

    // Remove the newline character if present
    cAFirst[strcspn(cAFirst, "\n")] = '\0';

    for (size_t i = 0; i < strlen(cAFirst); i++) {
        if (isupper(cAFirst[i])) {
            uc++;
        }
        if (islower(cAFirst[i])) {
            lc++;
        }
    }

    printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    return 0;
}
