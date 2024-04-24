#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int k = 0, uc = 0, lc = 0;

    fgets(cAFirst, 25, stdin);

    // Find the length of the input string
    size_t len = strlen(cAFirst);

    for (size_t i = 0; i < len; i++) {
        k = (int)cAFirst[i];

        if (k >= 'A' && k <= 'Z') {
            uc++;
        }

        if (k >= 'a' && k <= 'z') {
            lc++;
        }
    }

    printf("Uppercase Letters = %i\nLowercase Letters = %i\n", uc, lc);

    return 0;
}
