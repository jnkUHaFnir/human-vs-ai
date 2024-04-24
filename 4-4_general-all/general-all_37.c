#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include for isupper and islower functions

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst, sizeof(cAFirst), stdin);

    for (size_t i = 0; i < strlen(cAFirst); i++) {
        if (isupper(cAFirst[i])) {
            uc++;
        }
        if (islower(cAFirst[i])) {
            lc++;
        }
    }

    printf("Uppercase Letters=%i\nLowercase Letters=%i\n", uc, lc);
    return 0;
}
