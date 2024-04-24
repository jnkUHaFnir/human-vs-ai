#include <stdio.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    if (fgets(cAFirst, sizeof(cAFirst), stdin) != NULL) {
        for (size_t i = 0; cAFirst[i] != '\0'; i++) {
            int k = (int)cAFirst[i];
            if ((k >= 'A') && (k <= 'Z')) {
                uc++;
            }
            if ((k >= 'a') && (k <= 'z')) {
                lc++;
            }
        }

        printf("Uppercase Letters=%i \nLowercase Letters=%i \n", uc, lc);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
