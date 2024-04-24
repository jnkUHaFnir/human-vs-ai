#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for isupper and islower functions

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0; // Initialize uc and lc to 0

    fgets(cAFirst, 25, stdin);

    for (size_t i = 0; i < strlen(cAFirst); i++) { // Use strlen(cAFirst) to loop through actual length of input
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
