#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst, sizeof(cAFirst), stdin);

    // Find the actual length of the input string
    size_t len = strlen(cAFirst);
    if (len > 0 && cAFirst[len - 1] == '\n') {
        cAFirst[len - 1] = '\0'; // Remove the newline character if present
        len--;
    }

    for (size_t i = 0; i < len; i++) {
        if (isupper(cAFirst[i])) {
            uc++;
        } else if (islower(cAFirst[i])) {
            lc++;
        }
    }

    printf("Uppercase Letters = %i\nLowercase Letters = %i\n", uc, lc);

    return 0;
}
