#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    if (fgets(cAFirst, sizeof(cAFirst), stdin) != NULL) {
        cAFirst[strcspn(cAFirst, "\n")] = '\0'; // Remove '\n' from the input
        size_t len = strlen(cAFirst);

        for (size_t i = 0; i < len; i++) {
            int k = cAFirst[i];
            if (k >= 'A' && k <= 'Z') {
                uc++;
            }
            if (k >= 'a' && k <= 'z') {
                lc++;
            }
        }

        printf("Uppercase Letters=%i\nLowercase Letters=%i\n", uc, lc);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
