#include <stdio.h>
#include <string.h>

int main()
{
    char cAFirst[25];
    int uc = 0, lc = 0;

    fgets(cAFirst, sizeof(cAFirst), stdin);
    cAFirst[strcspn(cAFirst, "\n")] = '\0'; // remove newline character if present

    size_t len = strlen(cAFirst);

    for (size_t i = 0; i < len; i++) {
        int k = (int)cAFirst[i];
        if ((k >= 'A') && (k <= 'Z')) {
            uc++;
        }
        if ((k >= 'a') && (k <= 'z')) {
            lc++;
        }
    }

    printf("Uppercase Letters = %i\nLowercase Letters = %i\n", uc, lc);
    return 0;
}
