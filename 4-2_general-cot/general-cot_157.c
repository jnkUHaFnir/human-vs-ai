#include <stdio.h>
#include <string.h>
#include <ctype.h> // Include ctype.h for isupper() and islower()

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst, 25, stdin);

    // Calculate the length of input
    size_t length = strlen(cAFirst);

    // Iterate through the input characters
    for (size_t i = 0; i < length; i++) {
        char currentChar = cAFirst[i];
        if (isupper(currentChar)) {
            uc++;
        }
        if (islower(currentChar)) {
            lc++;
        }
    }

    printf("Uppercase Letters=%i\nLowercase Letters=%i\n", uc, lc);
    return 0;
}
