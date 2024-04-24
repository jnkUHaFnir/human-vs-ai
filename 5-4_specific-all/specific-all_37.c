#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    if (fgets(cAFirst, 25, stdin) != NULL) {
        // Remove newline character if present
        cAFirst[strcspn(cAFirst, "\n")] = 0;

        for (size_t i = 0; i < strlen(cAFirst); i++) {
            if (cAFirst[i] >= 'A' && cAFirst[i] <= 'Z') {
                uc++;
            }
            if (cAFirst[i] >= 'a' && cAFirst[i] <= 'z') {
                lc++;
            }
        }

        printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
