#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int k = 0, uc = 0, lc = 0;

    fgets(cAFirst, 25, stdin);

    for (size_t i = 0; i < strlen(cAFirst); i++) {
        k = (int)cAFirst[i];

        if (k == 10) { // Skip newline character
            continue;
        }

        if ((k >= 65) && (k <= 90)) {
            uc++;
        }
        if ((k >= 97) && (k <= 122)) {
            lc++;
        }
    }

    printf("Uppercase Letters=%i\nLowercase Letters=%i\n", uc, lc);
    return 0;
}
